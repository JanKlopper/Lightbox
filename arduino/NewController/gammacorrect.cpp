#pragma once

#include <avr/pgmspace.h>
#include "gammacorrect.h"

PROGMEM prog_uint16_t gammaTable[256] = {
    // 8-bit intensity levels mapped to 12-bit PWM values corrected for the
    // non-linear sensitivity of the human eye. Gamma value = 2.2
    // Original function:
    //   gammaCorrected[i] = pow((float) i / 256, gamma) * 4096 + 1;
       0,    1,    1,    1,    1,    1,    2,    2,    3,    3,    4,    5,
       5,    6,    7,    8,   10,   11,   12,   14,   16,   17,   19,   21,
      23,   25,   27,   30,   32,   35,   37,   40,   43,   46,   49,   52,
      55,   59,   62,   66,   69,   73,   77,   81,   86,   90,   94,   99,
     104,  108,  113,  118,  123,  129,  134,  140,  145,  151,  157,  163,
     169,  175,  181,  188,  195,  201,  208,  215,  222,  229,  237,  244,
     252,  260,  268,  276,  284,  292,  300,  309,  317,  326,  335,  344,
     353,  363,  372,  382,  391,  401,  411,  421,  432,  442,  452,  463,
     474,  485,  496,  507,  518,  530,  541,  553,  565,  577,  589,  602,
     614,  626,  639,  652,  665,  678,  691,  705,  718,  732,  746,  760,
     774,  788,  803,  817,  832,  847,  862,  877,  892,  907,  923,  939,
     954,  970,  986, 1003, 1019, 1036, 1052, 1069, 1086, 1103, 1121, 1138,
    1156, 1173, 1191, 1209, 1227, 1246, 1264, 1283, 1302, 1320, 1339, 1359,
    1378, 1398, 1417, 1437, 1457, 1477, 1497, 1518, 1538, 1559, 1580, 1601,
    1622, 1643, 1665, 1686, 1708, 1730, 1752, 1774, 1797, 1819, 1842, 1865,
    1888, 1911, 1934, 1958, 1981, 2005, 2029, 2053, 2077, 2102, 2126, 2151,
    2176, 2201, 2226, 2251, 2277, 2302, 2328, 2354, 2380, 2406, 2433, 2459,
    2486, 2513, 2540, 2567, 2595, 2622, 2650, 2678, 2706, 2734, 2762, 2790,
    2819, 2848, 2877, 2906, 2935, 2965, 2994, 3024, 3054, 3084, 3114, 3145,
    3175, 3206, 3237, 3268, 3299, 3330, 3362, 3393, 3425, 3457, 3490, 3522,
    3554, 3587, 3620, 3653, 3686, 3719, 3753, 3786, 3820, 3854, 3888, 3923,
    3957, 3992, 4026, 4061};

int gammaCorrected(byte level) {
  return pgm_read_word_near(gammaTable + level);
}