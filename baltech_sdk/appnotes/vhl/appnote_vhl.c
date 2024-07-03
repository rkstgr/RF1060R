/* This file demonstrates how to access a card via VHL. As VHL is card type
 * agnostic, this application note works with every kind of card supported by
 * baltech readers.
 *
 * ATTENTION: To make this sample not only reading the cards type and UID,
 *            the reader has to be configured with VHL file(s).
 *            For simple mifare cards (with factory keys 0xFF 0xFF ... 0xFF)
 *            start the ConfigEditor in the Baltech ToolSuite any load
 *            ``/appnotes/vhl/00000-0006-0000-01_SDK_AppNote_VHL.balcfg``
 *            into the reader (or alternatively the corresponding .bec file
 *            with the Baltech Uploader)
 *
 *            Furthermore the first sector has to contain a ascii name of
 *            length CARD_NAME_LEN and the second sector has to contain a
 *            ascii decimal number of length COUNTER_VAL_LEN. Both sectors
 *            can be written with the ID-engine explorer (tab VHL) after
 *            loading the configuration.
 */
 
 
#include <stdio.h>
#include <baltech_api.h>


// number of repetitions of selecting and reading/writing a card.
#define REPETITIONS             3


// VHL file ID of VHL files
#define VHL_FILE_CARD_NAME      "CardNameDemo"
#define VHL_FILE_COUNTER_VAL    "CounterValueDemo"

#define CARD_NAME_LEN           16
#define COUNTER_VAL_LEN         8


static void exit_on_error(brp_errcode errcode, char *errormessage,
						  brp_protocol dev)
{
	if (errcode != BRP_OK)
	{
		char * errname = brp_map_errcode(errcode);
		if (errname == NULL)
			fprintf(stderr, "%s [brp_errcode:%08X]\n", errormessage, errcode);
		else
			fprintf(stderr, "%s [%s]\n", errormessage, errname);
		brp_destroy(dev);
		exit(EXIT_FAILURE);
	}
}


static char *  map_card_type_to_name(brp_CardType card_type)
{
	switch (card_type)
	{
		case brp_CardType_MifareClassic: return "MifareClassic";
		case brp_CardType_Iso14443aGeneric: return "Iso14443aGeneric";
		case brp_CardType_Iso14443aInterIndustry: return "Iso14443aInterIndustry";
		case brp_CardType_MifareUltraLight: return "MifareUltraLight";
		case brp_CardType_MifareDesfire: return "MifareDesfire";
		case brp_CardType_InfineonSle55: return "InfineonSle55";
		case brp_CardType_Iso14443aIntIndustryMif: return "Iso14443aIntIndustryMif";
		case brp_CardType_MifarePlusL2: return "MifarePlusL2";
		case brp_CardType_LEGICAdvantIso14443a: return "LEGICAdvantIso14443a";
		case brp_CardType_MifarePlusL3: return "MifarePlusL3";
		case brp_CardType_LEGICPrimeLegacy: return "LEGICPrimeLegacy";
		case brp_CardType_LEGICAdvantLegacy: return "LEGICAdvantLegacy";
		case brp_CardType_Iso15693: return "Iso15693";
		case brp_CardType_LEGICAdvantIso15693: return "LEGICAdvantIso15693";
		case brp_CardType_Iso14443bUnknown: return "Iso14443bUnknown";
		case brp_CardType_Iso14443bIntIndustry: return "Iso14443bIntIndustry";
		case brp_CardType_IClassIso14B: return "IClassIso14B";
		case brp_CardType_IClassIso14B2: return "IClassIso14B2";
		case brp_CardType_IClass: return "IClass";
		case brp_CardType_Felica: return "Felica";
		case brp_CardType_EM4205: return "EM4205";
		case brp_CardType_EM4100: return "EM4100";
		case brp_CardType_EM4450: return "EM4450";
		case brp_CardType_Pyramid: return "Pyramid";
		case brp_CardType_HidProx32: return "HidProx32";
		case brp_CardType_Keri: return "Keri";
		case brp_CardType_Quadrakey: return "Quadrakey";
		case brp_CardType_HidIndala: return "HidIndala";
		case brp_CardType_HidAwid: return "HidAwid";
		case brp_CardType_HidProx: return "HidProx";
		case brp_CardType_HidIoprox: return "HidIoprox";
		case brp_CardType_Hitag1S: return "Hitag1S";
		case brp_CardType_Hitag2M: return "Hitag2M";
		case brp_CardType_Hitag2B: return "Hitag2B";
		case brp_CardType_TTF: return "TTF";
		case brp_CardType_STSRIX: return "STSRIX";
		case brp_CardType_SecuraKey: return "SecuraKey";
		case brp_CardType_GProx: return "GProx";
		case brp_CardType_HidIndalaSecure: return "HidIndalaSecure";
		case brp_CardType_Cotag: return "Cotag";
		case brp_CardType_Idteck: return "Idteck";
		case brp_CardType_BluetoothMce: return "BluetoothMce";
		case brp_CardType_LEGICPrime: return "LEGICPrime";
		case brp_CardType_HidSio: return "HidSio";
		default: return "UNKNOWN";
	}
}


static void poll_for_card(brp_protocol dev)
{
	brp_CardFamilies card_family_filter = {
			.Iso14443A = true,
			.Iso14443B = true,
			.Khz125Part1 = true,
			.Khz125Part2 = true,
			
			////// the following card families are commented out and thus
			////// are ignored by VHL:
			
			//.Felica = true,
			//.IClass = true,
			//.Iso15693 = true,
			//.BluetoothMce = true,
			//.LegicPrime = true,
			//.Srix = true,
	};
	printf("\n");
	printf("searching for card...");
	while (true)
	{
		brp_CardType card_type;
		brp_errcode errcode = brp_VHL_Select(dev,
				card_family_filter, false, false, &card_type);
		if (errcode == BRP_OK)
		{
			printf("\n");
			printf("  detected a %s card\n", map_card_type_to_name(card_type));
			return;
		}
		else if (errcode == BRP_VHL_ErrNoTag)
			printf(".");
		else
			exit_on_error(errcode, "failed to select card", dev);
	}
}


static void show_card_uid(brp_protocol dev)
{
	brp_buf uid;
	size_t uid_len;
	brp_errcode errcode = brp_VHL_GetSnr(dev, &uid, &uid_len, NULL);
	exit_on_error(errcode, "failed to retrieve UID", dev);
	
	printf("  UID of card: \"");
	for (unsigned ndx = 0; ndx < uid_len; ndx++)
		printf("%02X ", uid[ndx]);
	printf("\"\n");
}


static void show_cards_name(brp_protocol dev, unsigned vhl_id)
{
	brp_buf name;
	brp_errcode errcode;
	errcode = brp_VHL_Read(dev, vhl_id, 0, CARD_NAME_LEN, &name, NULL, NULL);
	if (errcode != BRP_OK)
		printf("  failed to read name of card [errcode %08X]\n", errcode);

	printf("  Name Of Card is: \"");
	for (int ndx = 0; ndx < CARD_NAME_LEN && name[ndx] != '\0'; ndx++)
		printf("%c", name[ndx]);
	printf("\"\n");
}


static void increment_cards_counter_value(brp_protocol dev, unsigned vhl_id)
{
	char ctr_str_in[COUNTER_VAL_LEN + 1], ctr_str_out[COUNTER_VAL_LEN + 1];
	brp_buf ctr_str;
	brp_errcode errcode;
	errcode = brp_VHL_Read(dev, vhl_id, 0, COUNTER_VAL_LEN, &ctr_str,
			NULL, NULL);
	if (errcode != BRP_OK)
		printf("  failed to read ctr value of card [errcode %08X]\n", errcode);

	memcpy(ctr_str_in, ctr_str, COUNTER_VAL_LEN);
	ctr_str_in[COUNTER_VAL_LEN] = 0;
	unsigned long ctr = strtoul((char*)ctr_str, NULL, 10);
	ctr += 1;
	snprintf(ctr_str_out, COUNTER_VAL_LEN+1, "%08ld", ctr);
	
	errcode = brp_VHL_Write(dev, vhl_id, 0,
			(brp_buf) ctr_str_out, COUNTER_VAL_LEN);
	if (errcode != BRP_OK)
		printf("  failed to write ctr value to card [errcode %08X]\n", errcode);
	
	printf("  incremented counter value to %s\n", ctr_str_out);
}


int main(int argc, char *argv[])
{
	brp_errcode errcode;
	int cnt;
	unsigned vhlid_cardname, vhlid_ctrval;
	bool is_configured_vhlfile_cardname, is_configured_vhlfile_ctrval;
	
	brp_protocol dev = brp_create();
	brp_set_io(dev, brp_create_usb_hid(0));
	errcode = brp_open(dev);
	exit_on_error(errcode, "failed to connect to USB/HID device", dev);
	
	// resolve VHL file IDs should be done BEFORE loop due to optimitation
	errcode = brp_VHL_ResolveFilename(dev, VHL_FILE_CARD_NAME, &vhlid_cardname);
	is_configured_vhlfile_cardname = (errcode == BRP_OK);
	if (!is_configured_vhlfile_cardname)
		printf("WARNING: no %s VhlFile configured\n", VHL_FILE_CARD_NAME);
	errcode = brp_VHL_ResolveFilename(dev, VHL_FILE_COUNTER_VAL, &vhlid_ctrval);
	is_configured_vhlfile_ctrval = (errcode == BRP_OK);
	if (!is_configured_vhlfile_ctrval)
		printf("WARNING: no %s VhlFile configured\n", VHL_FILE_COUNTER_VAL);
	
	printf("SEARCHES %i TIMES FOR CARDS:\n", REPETITIONS);
	for (cnt = 0; cnt < REPETITIONS; cnt++)
	{
		poll_for_card(dev);
		show_card_uid(dev);
		if (is_configured_vhlfile_cardname)
			show_cards_name(dev, vhlid_cardname);
		if (is_configured_vhlfile_ctrval)
			increment_cards_counter_value(dev, vhlid_ctrval);
	}
	
	brp_destroy(dev);
	return EXIT_SUCCESS;
}
