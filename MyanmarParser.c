//
//  MyanmarParser.c
//  ngram-test
//
//  Created by Thant Thet Khin Zaw on 7/9/15.
//  Copyright (c) 2015 myOpenware. All rights reserved.
//

#include "MyanmarParser.h"

enum {
    MY_SYLLABLE_UNKNOWN,
    MY_SYLLABLE_CONSONANT,
    MY_SYLLABLE_MEDIAL,
    MY_SYLLABLE_VOWEL,
    MY_SYLLABLE_TONE,
    MY_SYLLABLE_1039,
    MY_SYLLABLE_103A,
    MY_SYLLABLE_NUMBER,
    MY_SYLLABLE_SECTION
} MY_SYLLABLE;

enum {
    LANG_MY
} LANG;

int CHAR_PART[] = {
    MY_SYLLABLE_CONSONANT,//1000;MYANMAR LETTER KA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1001;MYANMAR LETTER KHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1002;MYANMAR LETTER GA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1003;MYANMAR LETTER GHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1004;MYANMAR LETTER NGA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1005;MYANMAR LETTER CA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1006;MYANMAR LETTER CHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1007;MYANMAR LETTER JA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1008;MYANMAR LETTER JHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1009;MYANMAR LETTER NYA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//100A;MYANMAR LETTER NNYA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//100B;MYANMAR LETTER TTA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//100C;MYANMAR LETTER TTHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//100D;MYANMAR LETTER DDA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//100E;MYANMAR LETTER DDHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//100F;MYANMAR LETTER NNA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1010;MYANMAR LETTER TA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1011;MYANMAR LETTER THA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1012;MYANMAR LETTER DA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1013;MYANMAR LETTER DHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1014;MYANMAR LETTER NA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1015;MYANMAR LETTER PA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1016;MYANMAR LETTER PHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1017;MYANMAR LETTER BA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1018;MYANMAR LETTER BHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1019;MYANMAR LETTER MA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//101A;MYANMAR LETTER YA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//101B;MYANMAR LETTER RA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//101C;MYANMAR LETTER LA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//101D;MYANMAR LETTER WA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//101E;MYANMAR LETTER SA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//101F;MYANMAR LETTER HA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1020;MYANMAR LETTER LLA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1021;MYANMAR LETTER A;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1022;MYANMAR LETTER SHAN A;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1023;MYANMAR LETTER I;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1024;MYANMAR LETTER II;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1025;MYANMAR LETTER U;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1026;MYANMAR LETTER UU;Lo;0;L;1025 102E;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1027;MYANMAR LETTER E;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1028;MYANMAR LETTER MON E;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1029;MYANMAR LETTER O;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//102A;MYANMAR LETTER AU;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//102B;MYANMAR VOWEL SIGN TALL AA;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//102C;MYANMAR VOWEL SIGN AA;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//102D;MYANMAR VOWEL SIGN I;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//102E;MYANMAR VOWEL SIGN II;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//102F;MYANMAR VOWEL SIGN U;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1030;MYANMAR VOWEL SIGN UU;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1031;MYANMAR VOWEL SIGN E;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1032;MYANMAR VOWEL SIGN AI;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1033;MYANMAR VOWEL SIGN MON II;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1034;MYANMAR VOWEL SIGN MON O;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1035;MYANMAR VOWEL SIGN E ABOVE;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1036;MYANMAR SIGN ANUSVARA;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_TONE,//1037;MYANMAR SIGN DOT BELOW;Mn;7;NSM;;;;;N;;;;;
    MY_SYLLABLE_TONE,//1038;MYANMAR SIGN VISARGA;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_1039,//1039;MYANMAR SIGN VIRAMA;Mn;9;NSM;;;;;N;;;;;
    MY_SYLLABLE_103A,//103A;MYANMAR SIGN ASAT;Mn;9;NSM;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//103B;MYANMAR CONSONANT SIGN MEDIAL YA;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//103C;MYANMAR CONSONANT SIGN MEDIAL RA;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//103D;MYANMAR CONSONANT SIGN MEDIAL WA;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//103E;MYANMAR CONSONANT SIGN MEDIAL HA;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//103F;MYANMAR LETTER GREAT SA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_NUMBER,//1040;MYANMAR DIGIT ZERO;Nd;0;L;;0;0;0;N;;;;;
    MY_SYLLABLE_NUMBER,//1041;MYANMAR DIGIT ONE;Nd;0;L;;1;1;1;N;;;;;
    MY_SYLLABLE_NUMBER,//1042;MYANMAR DIGIT TWO;Nd;0;L;;2;2;2;N;;;;;
    MY_SYLLABLE_NUMBER,//1043;MYANMAR DIGIT THREE;Nd;0;L;;3;3;3;N;;;;;
    MY_SYLLABLE_NUMBER,//1044;MYANMAR DIGIT FOUR;Nd;0;L;;4;4;4;N;;;;;
    MY_SYLLABLE_NUMBER,//1045;MYANMAR DIGIT FIVE;Nd;0;L;;5;5;5;N;;;;;
    MY_SYLLABLE_NUMBER,//1046;MYANMAR DIGIT SIX;Nd;0;L;;6;6;6;N;;;;;
    MY_SYLLABLE_NUMBER,//1047;MYANMAR DIGIT SEVEN;Nd;0;L;;7;7;7;N;;;;;
    MY_SYLLABLE_NUMBER,//1048;MYANMAR DIGIT EIGHT;Nd;0;L;;8;8;8;N;;;;;
    MY_SYLLABLE_NUMBER,//1049;MYANMAR DIGIT NINE;Nd;0;L;;9;9;9;N;;;;;
    MY_SYLLABLE_SECTION,//104A;MYANMAR SIGN LITTLE SECTION;Po;0;L;;;;;N;;;;;
    MY_SYLLABLE_SECTION,//104B;MYANMAR SIGN SECTION;Po;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//104C;MYANMAR SYMBOL LOCATIVE;Po;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//104D;MYANMAR SYMBOL COMPLETED;Po;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//104E;MYANMAR SYMBOL AFOREMENTIONED;Po;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//104F;MYANMAR SYMBOL GENITIVE;Po;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1050;MYANMAR LETTER SHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1051;MYANMAR LETTER SSA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1052;MYANMAR LETTER VOCALIC R;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1053;MYANMAR LETTER VOCALIC RR;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1054;MYANMAR LETTER VOCALIC L;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1055;MYANMAR LETTER VOCALIC LL;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1056;MYANMAR VOWEL SIGN VOCALIC R;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1057;MYANMAR VOWEL SIGN VOCALIC RR;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1058;MYANMAR VOWEL SIGN VOCALIC L;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1059;MYANMAR VOWEL SIGN VOCALIC LL;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//105A;MYANMAR LETTER MON NGA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//105B;MYANMAR LETTER MON JHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//105C;MYANMAR LETTER MON BBA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//105D;MYANMAR LETTER MON BBE;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//105E;MYANMAR CONSONANT SIGN MON MEDIAL NA;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//105F;MYANMAR CONSONANT SIGN MON MEDIAL MA;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//1060;MYANMAR CONSONANT SIGN MON MEDIAL LA;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1061;MYANMAR LETTER SGAW KAREN SHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1062;MYANMAR VOWEL SIGN SGAW KAREN EU;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1063;MYANMAR TONE MARK SGAW KAREN HATHI;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1064;MYANMAR TONE MARK SGAW KAREN KE PHO;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1065;MYANMAR LETTER WESTERN PWO KAREN THA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1066;MYANMAR LETTER WESTERN PWO KAREN PWA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1067;MYANMAR VOWEL SIGN WESTERN PWO KAREN EU;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1068;MYANMAR VOWEL SIGN WESTERN PWO KAREN UE;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//1069;MYANMAR SIGN WESTERN PWO KAREN TONE-1;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//106A;MYANMAR SIGN WESTERN PWO KAREN TONE-2;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//106B;MYANMAR SIGN WESTERN PWO KAREN TONE-3;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//106C;MYANMAR SIGN WESTERN PWO KAREN TONE-4;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//106D;MYANMAR SIGN WESTERN PWO KAREN TONE-5;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//106E;MYANMAR LETTER EASTERN PWO KAREN NNA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//106F;MYANMAR LETTER EASTERN PWO KAREN YWA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1070;MYANMAR LETTER EASTERN PWO KAREN GHWA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1071;MYANMAR VOWEL SIGN GEBA KAREN I;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1072;MYANMAR VOWEL SIGN KAYAH OE;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1073;MYANMAR VOWEL SIGN KAYAH U;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1074;MYANMAR VOWEL SIGN KAYAH EE;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1075;MYANMAR LETTER SHAN KA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1076;MYANMAR LETTER SHAN KHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1077;MYANMAR LETTER SHAN GA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1078;MYANMAR LETTER SHAN CA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1079;MYANMAR LETTER SHAN ZA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//107A;MYANMAR LETTER SHAN NYA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//107B;MYANMAR LETTER SHAN DA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//107C;MYANMAR LETTER SHAN NA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//107D;MYANMAR LETTER SHAN PHA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//107E;MYANMAR LETTER SHAN FA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//107F;MYANMAR LETTER SHAN BA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1080;MYANMAR LETTER SHAN THA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//1081;MYANMAR LETTER SHAN HA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_MEDIAL,//1082;MYANMAR CONSONANT SIGN SHAN MEDIAL WA;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1083;MYANMAR VOWEL SIGN SHAN AA;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1084;MYANMAR VOWEL SIGN SHAN E;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1085;MYANMAR VOWEL SIGN SHAN E ABOVE;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_VOWEL,//1086;MYANMAR VOWEL SIGN SHAN FINAL Y;Mn;0;NSM;;;;;N;;;;;
    MY_SYLLABLE_TONE,//1087;MYANMAR SIGN SHAN TONE-2;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//1088;MYANMAR SIGN SHAN TONE-3;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//1089;MYANMAR SIGN SHAN TONE-5;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//108A;MYANMAR SIGN SHAN TONE-6;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//108B;MYANMAR SIGN SHAN COUNCIL TONE-2;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//108C;MYANMAR SIGN SHAN COUNCIL TONE-3;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//108D;MYANMAR SIGN SHAN COUNCIL EMPHATIC TONE;Mn;220;NSM;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT,//108E;MYANMAR LETTER RUMAI PALAUNG FA;Lo;0;L;;;;;N;;;;;
    MY_SYLLABLE_TONE,//108F;MYANMAR SIGN RUMAI PALAUNG TONE-5;Mc;0;L;;;;;N;;;;;
    MY_SYLLABLE_NUMBER,//1090;MYANMAR SHAN DIGIT ZERO;Nd;0;L;;0;0;0;N;;;;;
    MY_SYLLABLE_NUMBER,//1091;MYANMAR SHAN DIGIT ONE;Nd;0;L;;1;1;1;N;;;;;
    MY_SYLLABLE_NUMBER,//1092;MYANMAR SHAN DIGIT TWO;Nd;0;L;;2;2;2;N;;;;;
    MY_SYLLABLE_NUMBER,//1093;MYANMAR SHAN DIGIT THREE;Nd;0;L;;3;3;3;N;;;;;
    MY_SYLLABLE_NUMBER,//1094;MYANMAR SHAN DIGIT FOUR;Nd;0;L;;4;4;4;N;;;;;
    MY_SYLLABLE_NUMBER,//1095;MYANMAR SHAN DIGIT FIVE;Nd;0;L;;5;5;5;N;;;;;
    MY_SYLLABLE_NUMBER,//1096;MYANMAR SHAN DIGIT SIX;Nd;0;L;;6;6;6;N;;;;;
    MY_SYLLABLE_NUMBER,//1097;MYANMAR SHAN DIGIT SEVEN;Nd;0;L;;7;7;7;N;;;;;
    MY_SYLLABLE_NUMBER,//1098;MYANMAR SHAN DIGIT EIGHT;Nd;0;L;;8;8;8;N;;;;;
    MY_SYLLABLE_NUMBER,//1099;MYANMAR SHAN DIGIT NINE;Nd;0;L;;9;9;9;N;;;;;
    MY_SYLLABLE_TONE,//109A
    MY_SYLLABLE_TONE,//109B
    MY_SYLLABLE_TONE,//109C
    MY_SYLLABLE_TONE,//109D??
    MY_SYLLABLE_CONSONANT,//109E;MYANMAR SYMBOL SHAN ONE;So;0;L;;;;;N;;;;;
    MY_SYLLABLE_CONSONANT//109F;MYANMAR SYMBOL SHAN EXCLAMATION;So;0;L;;;;;N;;;;;
};

int get_char_class(wchar_t ch)
{
    if (0x1000 > ch || ch > 0x109F) {
        if (0xAA60 <= ch || ch < 0xAA7C) {
            if (ch == 0xAA70) {
                return MY_SYLLABLE_TONE;
            } else if (ch == 0xAA7B) {
                return MY_SYLLABLE_TONE;
            }
            return MY_SYLLABLE_CONSONANT;
        }
        return MY_SYLLABLE_UNKNOWN;
    }
    return CHAR_PART[ch - 0x1000];
}

int get_break_status(wchar_t before, wchar_t after)
{
    // first char = row, second char = column
    // 0=illegal, 1=no, 2=yes, 3=yes-line, 4=punctuation, 5=context,
    
    int BKSTATUS[9][9] = {
       // -  C  M  V  T 39 3A  N  S
        { 1, 3, 1, 1, 1, 1, 1, 1, 1 },// -
        { 3, 5, 1, 1, 1, 1, 1, 2, 4 },// C
        { 3, 5, 1, 1, 1, 0, 1, 2, 4 },// M
        { 3, 5, 0, 1, 1, 0, 1, 2, 4 },// V
        { 3, 2, 0, 1, 1, 0, 1, 2, 4 },// T
        { 3, 1, 0, 0, 0, 0, 0, 0, 0 },// 1039
        { 3, 2, 1, 1, 1, 1, 0, 2, 4 },// 103A
        { 3, 2, 1, 1, 1, 0, 0, 1, 4 },// N
        { 3, 2, 0, 0, 0, 0, 0, 2, 0 } // S
    };
    
    return BKSTATUS[get_char_class(before)][get_char_class(after)];
}

int evaluate_context(const uint16_t *text, int offset, int langHint)
{
    wchar_t dummytext[5]= {0};
    const uint16_t *textAtOffset = text + offset;
    int i = 0;
    while (*textAtOffset && i < 4) {
        dummytext[i++] = *textAtOffset++;
        dummytext[i] = '\0';
    }
    
    for (i = 0; i < 4; i++) {
        if (dummytext[i] == '\0') {
            dummytext[i] = ' ';
        }
    }
    
    if (dummytext[0] == 0x1021 && langHint == LANG_MY)
        return MY_PAIR_NO_BREAK;
    if (dummytext[1] == 0x002d)
        return MY_PAIR_NO_BREAK;
    if (dummytext[1] == 0x103F)
        return MY_PAIR_NO_BREAK;
    if (dummytext[2] == 0x1037 && dummytext[3] == 0x103A)
        return MY_PAIR_NO_BREAK;
    if (dummytext[2] == 0x1039)
        return MY_PAIR_NO_BREAK;
    else if (dummytext[2] == 0x103A && langHint == LANG_MY)
        // Karen (and also some loan words in Myanmar) can have a starting 103A
        return MY_PAIR_NO_BREAK;
    else
        return MY_PAIR_SYL_BREAK;
}

int get_next_syllable(const uint16_t *text, uint length, uint offset, int *breakTypeRet)
{
    int breakType = MY_PAIR_NO_BREAK;
    int i = offset;
    int foundCluster = 0;
    if (offset >= length) {
        *breakTypeRet = breakType;
        return length;
    }
    while (i + 1 < length) {
        wchar_t first = text[i];
        wchar_t second = text[i + 1];
        int breakStatus = get_break_status(first, second);
        switch (breakStatus) {
            case MY_PAIR_NO_BREAK:
                
                break;
            case MY_PAIR_SYL_BREAK:
            case MY_PAIR_WORD_BREAK:
            case MY_PAIR_PUNCTUATION:
            case MY_PAIR_ILLEGAL:
                breakType = breakStatus;
                foundCluster = 1;
                break;
            case MY_PAIR_CONTEXT:
                breakType = evaluate_context(text, i, LANG_MY);
                if (breakType != MY_PAIR_NO_BREAK)
                    foundCluster = 1;
                break;
            default:
                printf ("Unexpected status: %d", breakStatus);
                break;
        }
        if (foundCluster == 1) {
            break;
        }
        i ++;
    }
    if (i + 1 == length)
        breakType = MY_PAIR_EOL;
    *breakTypeRet = breakType;
    return i + 1;
}

int is_myanmar_char(u_int16_t ch)
{
    if ((0x1000 <= ch && ch <= 0x109f) || (0xaa60 <= ch && ch <= 0xaa7f))
        return 1;
    return 0;
}
