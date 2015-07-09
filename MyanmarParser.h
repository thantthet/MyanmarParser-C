//
//  MyanmarParser.h
//  ngram-test
//
//  Created by Thant Thet Khin Zaw on 7/9/15.
//  Copyright (c) 2015 myOpenware. All rights reserved.
//

#ifndef __ngram_test__MyanmarParser__
#define __ngram_test__MyanmarParser__

#include <stdio.h>

enum {
    MY_PAIR_ILLEGAL,
    MY_PAIR_NO_BREAK,
    MY_PAIR_SYL_BREAK,
    MY_PAIR_WORD_BREAK,
    MY_PAIR_PUNCTUATION,
    MY_PAIR_CONTEXT,
    MY_PAIR_EOL
};

int get_next_syllable(const uint16_t *text, uint length, uint offset, int *breakTypeRet);

#endif /* defined(__ngram_test__MyanmarParser__) */
