
/*  A Bison parser, made from inform.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	NUM	257
#define	DFILE	258
#define	CONDITION	259
#define	ALIAS	260
#define	RALIAS	261
#define	UNALIAS	262
#define	DUMPMEM	263
#define	AUTOMAP	264
#define	HELP	265
#define	UNDO	266
#define	REDO	267
#define	LANGUAGE	268
#define	INFOSOURCE	269
#define	INFOSOURCES	270
#define	COPYING	271
#define	WARRANTY	272
#define	PRINT	273
#define	SET	274
#define	MOVE	275
#define	TO	276
#define	GIVE	277
#define	REMOVE	278
#define	JUMP	279
#define	CONT	280
#define	STEP	281
#define	NEXT	282
#define	UNTIL	283
#define	STEPI	284
#define	NEXTI	285
#define	FINISH	286
#define	BREAK	287
#define	DELETE	288
#define	IF	289
#define	COND	290
#define	IGNORE	291
#define	BREAKPOINTS	292
#define	RESTORE	293
#define	RESTART	294
#define	QUIT	295
#define	RECORDON	296
#define	RECORDOFF	297
#define	REPLAY	298
#define	REPLAYOFF	299
#define	SYMBOL_FILE	300
#define	FRAME	301
#define	SELECT_FRAME	302
#define	BACKTRACE	303
#define	UP_FRAME	304
#define	DOWN_FRAME	305
#define	UP_SILENTLY	306
#define	DOWN_SILENTLY	307
#define	DISPLAY	308
#define	UNDISPLAY	309
#define	DISABLE_DISPLAY	310
#define	ENABLE_DISPLAY	311
#define	DISABLE_BREAK	312
#define	ENABLE_BREAK	313
#define	OBJECT_TREE	314
#define	FIND	315
#define	LIST_GLOBALS	316
#define	BTRUE	317
#define	BFALSE	318
#define	NOTHING	319
#define	PARENT	320
#define	CHILD	321
#define	SIBLING	322
#define	CHILDREN	323
#define	RANDOM	324
#define	ANDAND	325
#define	OROR	326
#define	NOTNOT	327
#define	OR	328
#define	BYTEARRAY	329
#define	WORDARRAY	330
#define	precNEG	331
#define	NUMBER	332
#define	OBJECT	333
#define	ROUTINE	334
#define	STRING	335
#define	GLOBAL	336
#define	LOCAL	337
#define	INCREMENT	338
#define	DECREMENT	339
#define	PROPADDR	340
#define	PROPLENGTH	341
#define	SUPERCLASS	342

#line 1 "inform.y"

/*  Nitfol - z-machine interpreter using Glk for output.
    Copyright (C) 1999  Evin Robertson

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.

    The author can be reached at ecr+@andrew.cmu.edu
*/

#include "nitfol.h"
#include <ctype.h>

/* bison uses str* functions; make it use n_str* instead... */
#ifndef n_strcat
#define strcat(d, s) n_strcat(d, s)
#endif
#ifndef n_strlen
#define strlen(s) n_strlen(s)
#endif
#ifndef n_strcpy
#define strcpy(d, s) n_strcpy(d, s)
#endif
  
  
#ifdef DEBUGGING
  
  typedef struct zword_list zword_list;
  struct zword_list {
    zword_list *next;
    zword item;
  };

  typedef struct cond_list cond_list;
  struct cond_list {
    cond_list *next;
    zword val;
    BOOL (*condfunc)(zword a, zword b);
    BOOL opposite;
  };

  cond_list *condlist;
  
  static z_typed z_t(z_typed a, z_typed b, zword v);
  
  static const char *lex_expression;
  static int lex_offset;

  static const char *lex_tail(void) {
    const char *t = lex_expression + lex_offset;
    while(*t == ' ')
      t++;
    lex_offset = n_strlen(lex_expression);
    return t;
  }
  
  static z_typed inform_result;
  
  static int yylex(void);
  static void yyerror(const char *s);
  static void inform_help(void);
  
  int ignoreeffects;

#define YYERROR_VERBOSE
  
/*
#define YYDEBUG 1
*/


#line 84 "inform.y"
typedef union {
  glui32 pcoffset;
  infix_file *filenum;
  z_typed val;
  
  zword_list *zlist;

  struct {
    BOOL (*condfunc)(zword a, zword b);
    BOOL opposite;
  } cond;

  BOOL flag;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		208
#define	YYFLAG		-32768
#define	YYNTBASE	104

#define YYTRANSLATE(x) ((unsigned)(x) <= 342 ? yytranslate[x] : 114)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,   101,     2,    81,    82,     2,    98,
   103,    79,    77,    71,    78,    99,    80,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,   102,     2,     2,
    72,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    83,     2,    84,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    73,    74,    75,    76,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,   100
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     3,     5,     7,     9,    11,    13,    15,    17,
    19,    21,    23,    25,    27,    29,    31,    33,    35,    38,
    41,    43,    46,    49,    52,    57,    59,    62,    64,    66,
    69,    73,    78,    81,    84,    86,    89,    91,    94,    96,
    99,   101,   103,   106,   108,   111,   113,   116,   120,   123,
   127,   130,   132,   135,   138,   141,   143,   145,   147,   149,
   151,   153,   156,   159,   161,   164,   166,   169,   171,   174,
   176,   179,   181,   184,   188,   190,   193,   196,   200,   203,
   205,   209,   210,   214,   216,   218,   222,   226,   227,   232,
   234,   236,   238,   240,   244,   249,   254,   259,   264,   269,
   274,   275,   280,   281,   286,   289,   293,   297,   301,   305,
   309,   313,   317,   320,   324,   328,   331,   334,   337,   340,
   343,   347,   351,   355,   358,   361,   364,   367,   370,   373
};

static const short yyrhs[] = {    -1,
   101,     0,     9,     0,     6,     0,     7,     0,     8,     0,
    10,     0,    11,     0,    40,     0,    39,     0,    42,     0,
    43,     0,    44,     0,    45,     0,    41,     0,    12,     0,
    13,     0,    46,     0,    19,   108,     0,    20,   108,     0,
    54,     0,    55,     3,     0,    56,     3,     0,    57,     3,
     0,    21,   108,    22,   108,     0,    60,     0,    60,   108,
     0,    61,     0,    62,     0,    62,   108,     0,    23,   108,
     3,     0,    23,   108,    84,     3,     0,    24,   108,     0,
    25,   105,     0,    26,     0,    26,     3,     0,    27,     0,
    27,     3,     0,    28,     0,    28,     3,     0,    29,     0,
    30,     0,    30,     3,     0,    31,     0,    31,     3,     0,
    32,     0,    33,   105,     0,    33,   105,    35,     0,    36,
     3,     0,    37,     3,     3,     0,    34,     3,     0,    38,
     0,    38,     3,     0,    58,     3,     0,    59,     3,     0,
    14,     0,    15,     0,    16,     0,    17,     0,    18,     0,
    47,     0,    47,     3,     0,    48,     3,     0,    50,     0,
    50,     3,     0,    52,     0,    52,     3,     0,    51,     0,
    51,     3,     0,    53,     0,    53,     3,     0,    49,     0,
    49,     3,     0,    49,    78,     3,     0,     3,     0,    77,
     3,     0,    78,     3,     0,     4,   102,     3,     0,    79,
     3,     0,   111,     0,   106,    76,   111,     0,     0,   111,
    71,   107,     0,   111,     0,   109,     0,   108,    71,   111,
     0,   108,    71,   109,     0,     0,   111,     5,   110,   106,
     0,     3,     0,    64,     0,    63,     0,    65,     0,   111,
    72,   111,     0,    66,    98,   108,   103,     0,    67,    98,
   108,   103,     0,    68,    98,   108,   103,     0,    69,    98,
   108,   103,     0,    70,    98,   108,   103,     0,   111,    98,
   107,   103,     0,     0,   111,    73,   112,   111,     0,     0,
   111,    74,   113,   111,     0,    75,   111,     0,   111,    77,
   111,     0,   111,    78,   111,     0,   111,    79,   111,     0,
   111,    80,   111,     0,   111,    81,   111,     0,   111,    82,
   111,     0,   111,    83,   111,     0,    84,   111,     0,   111,
    85,   111,     0,   111,    86,   111,     0,    78,   111,     0,
    94,   111,     0,   111,    94,     0,    95,   111,     0,   111,
    95,     0,   111,    96,   111,     0,   111,    97,   111,     0,
   111,    99,   111,     0,    88,   111,     0,    89,   111,     0,
    90,   111,     0,    91,   111,     0,    92,   111,     0,    93,
   111,     0,    98,   108,   103,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   130,   132,   134,   142,   144,   146,   148,   150,   152,   154,
   165,   167,   169,   171,   173,   175,   182,   189,   198,   200,
   202,   204,   206,   208,   210,   212,   214,   216,   221,   239,
   255,   257,   259,   261,   263,   265,   267,   269,   271,   273,
   275,   277,   279,   281,   283,   285,   287,   289,   291,   293,
   295,   297,   299,   301,   303,   305,   307,   309,   311,   313,
   315,   317,   319,   321,   323,   325,   327,   329,   331,   333,
   335,   337,   339,   341,   349,   350,   351,   352,   353,   357,
   364,   377,   378,   382,   383,   384,   385,   389,   390,   393,
   395,   397,   399,   402,   405,   407,   409,   411,   414,   424,
   442,   443,   444,   445,   446,   449,   451,   453,   455,   457,
   459,   461,   463,   466,   468,   471,   474,   476,   478,   480,
   483,   485,   488,   496,   498,   500,   502,   504,   506,   508
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","NUM","DFILE",
"CONDITION","ALIAS","RALIAS","UNALIAS","DUMPMEM","AUTOMAP","HELP","UNDO","REDO",
"LANGUAGE","INFOSOURCE","INFOSOURCES","COPYING","WARRANTY","PRINT","SET","MOVE",
"TO","GIVE","REMOVE","JUMP","CONT","STEP","NEXT","UNTIL","STEPI","NEXTI","FINISH",
"BREAK","DELETE","IF","COND","IGNORE","BREAKPOINTS","RESTORE","RESTART","QUIT",
"RECORDON","RECORDOFF","REPLAY","REPLAYOFF","SYMBOL_FILE","FRAME","SELECT_FRAME",
"BACKTRACE","UP_FRAME","DOWN_FRAME","UP_SILENTLY","DOWN_SILENTLY","DISPLAY",
"UNDISPLAY","DISABLE_DISPLAY","ENABLE_DISPLAY","DISABLE_BREAK","ENABLE_BREAK",
"OBJECT_TREE","FIND","LIST_GLOBALS","BTRUE","BFALSE","NOTHING","PARENT","CHILD",
"SIBLING","CHILDREN","RANDOM","','","'='","ANDAND","OROR","NOTNOT","OR","'+'",
"'-'","'*'","'/'","'%'","'&'","'|'","'~'","BYTEARRAY","WORDARRAY","precNEG",
"NUMBER","OBJECT","ROUTINE","STRING","GLOBAL","LOCAL","INCREMENT","DECREMENT",
"PROPADDR","PROPLENGTH","'('","'.'","SUPERCLASS","'#'","':'","')'","input","linespec",
"orlist","arglist","commaexp","condexp","@1","exp","@2","@3", NULL
};
#endif

static const short yyr1[] = {     0,
   104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
   104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
   104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
   104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
   104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
   104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
   104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
   104,   104,   104,   104,   105,   105,   105,   105,   105,   106,
   106,   107,   107,   108,   108,   108,   108,   110,   109,   111,
   111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
   112,   111,   113,   111,   111,   111,   111,   111,   111,   111,
   111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
   111,   111,   111,   111,   111,   111,   111,   111,   111,   111
};

static const short yyr2[] = {     0,
     0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
     1,     2,     2,     2,     4,     1,     2,     1,     1,     2,
     3,     4,     2,     2,     1,     2,     1,     2,     1,     2,
     1,     1,     2,     1,     2,     1,     2,     3,     2,     3,
     2,     1,     2,     2,     2,     1,     1,     1,     1,     1,
     1,     2,     2,     1,     2,     1,     2,     1,     2,     1,
     2,     1,     2,     3,     1,     2,     2,     3,     2,     1,
     3,     0,     3,     1,     1,     3,     3,     0,     4,     1,
     1,     1,     1,     3,     4,     4,     4,     4,     4,     4,
     0,     4,     0,     4,     2,     3,     3,     3,     3,     3,
     3,     3,     2,     3,     3,     2,     2,     2,     2,     2,
     3,     3,     3,     2,     2,     2,     2,     2,     2,     3
};

static const short yydefact[] = {     1,
     4,     5,     6,     3,     7,     8,    16,    17,    56,    57,
    58,    59,    60,     0,     0,     0,     0,     0,     0,    35,
    37,    39,    41,    42,    44,    46,     0,     0,     0,     0,
    52,    10,     9,    15,    11,    12,    13,    14,    18,    61,
     0,    72,    64,    68,    66,    70,    21,     0,     0,     0,
     0,     0,    26,    28,    29,     2,    90,    92,    91,    93,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    19,    85,    84,
    20,     0,     0,    33,    75,     0,     0,     0,     0,    34,
    36,    38,    40,    43,    45,    47,    51,    49,     0,    53,
    62,    63,    73,     0,    65,    69,    67,    71,    22,    23,
    24,    54,    55,    27,    30,     0,     0,     0,     0,     0,
   105,   116,   113,   124,   125,   126,   127,   128,   129,   117,
   119,     0,     0,    88,     0,   101,   103,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   118,   120,     0,     0,
    82,     0,     0,    31,     0,     0,    76,    77,    79,    48,
    50,    74,     0,     0,     0,     0,     0,   130,    87,    86,
     0,    94,     0,     0,   106,   107,   108,   109,   110,   111,
   112,   114,   115,   121,   122,     0,     0,   123,    25,    32,
    78,    95,    96,    97,    98,    99,    89,    80,   102,   104,
   100,    82,     0,    83,    81,     0,     0,     0
};

static const short yydefgoto[] = {   206,
    90,   197,   186,    78,    79,   171,    80,   173,   174
};

static const short yypact[] = {   136,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   155,   155,   155,   155,   155,    15,    28,
    33,    34,-32768,    44,    45,-32768,    15,    46,    47,    48,
    55,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    56,
    57,    13,    58,    60,    69,    71,-32768,    72,    83,    92,
    93,    94,   155,-32768,   155,-32768,-32768,-32768,-32768,-32768,
   -59,     1,     2,     8,     9,   155,   155,   155,   155,   155,
   155,   155,   155,   155,   155,   155,   155,    37,-32768,   194,
    37,    -7,    14,    37,-32768,    18,   107,   126,   133,-32768,
-32768,-32768,-32768,-32768,-32768,   102,-32768,-32768,   168,-32768,
-32768,-32768,-32768,   199,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    37,    37,   155,   155,   155,   155,   155,
    36,   -29,   115,   -29,   -29,   -29,   -29,   -29,   -29,    29,
    29,   -51,   155,-32768,   155,-32768,-32768,   155,   155,   155,
   155,   155,   155,   155,   155,   155,-32768,-32768,   155,   155,
   155,   155,   155,-32768,   200,   201,-32768,-32768,-32768,-32768,
-32768,-32768,   -50,   -49,   -48,   -47,   -46,-32768,-32768,   194,
   155,   251,   155,   155,   -53,   -53,   115,   115,   115,   115,
   115,   -29,   -29,   -64,   -64,   103,   223,-32768,    37,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    63,   251,    36,    36,
-32768,   155,   155,-32768,   251,   205,   207,-32768
};

static const short yypgoto[] = {-32768,
   181,-32768,    24,   -15,    82,-32768,   -62,-32768,-32768
};


#define	YYLAST		350


static const short yytable[] = {    81,
    82,    83,    84,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   153,   103,   154,    85,    86,   133,
   133,   133,   133,   133,   133,   140,   141,   142,   143,   144,
    91,   145,   146,   151,   152,    92,    93,   114,   116,   115,
   147,   148,   149,   150,   151,   152,    94,    95,    97,    98,
    99,   168,   192,   193,   194,   195,   196,   100,   101,   102,
   105,   132,   106,   133,   147,   148,   149,   150,   151,   152,
   170,   107,   172,   108,   109,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   133,   110,   184,   185,   187,   188,
   104,    87,    88,    89,   111,   112,   113,   155,   117,   118,
   163,   164,   165,   166,   167,   119,   120,   133,   198,   157,
   199,   200,   138,   139,   140,   141,   142,   143,   144,   156,
   145,   146,-32768,-32768,   149,   150,   151,   152,   158,   147,
   148,   149,   150,   151,   152,   159,   160,   189,   203,   187,
   205,     1,     2,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    14,    15,    16,    57,    17,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
   161,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,   134,   145,
   146,   162,   190,   191,   207,   201,   208,    96,   147,   148,
   149,   150,   151,   152,   169,     0,     0,    58,    59,    60,
    61,    62,    63,    64,    65,   204,     0,     0,     0,    66,
     0,     0,    67,     0,     0,     0,    56,     0,    68,     0,
     0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
     0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   135,   136,   137,     0,     0,
   138,   139,   140,   141,   142,   143,   144,     0,   145,   146,
     0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
   150,   151,   152,   202,   135,   136,   137,     0,     0,   138,
   139,   140,   141,   142,   143,   144,     0,   145,   146,     0,
     0,     0,     0,     0,     0,     0,   147,   148,   149,   150,
   151,   152,   135,   136,   137,     0,     0,   138,   139,   140,
   141,   142,   143,   144,     0,   145,   146,     0,     0,     0,
     0,     0,     0,     0,   147,   148,   149,   150,   151,   152
};

static const short yycheck[] = {    15,
    16,    17,    18,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    22,     3,     3,     3,     4,    71,
    71,    71,    71,    71,    71,    79,    80,    81,    82,    83,
     3,    85,    86,    98,    99,     3,     3,    53,    98,    55,
    94,    95,    96,    97,    98,    99,     3,     3,     3,     3,
     3,   103,   103,   103,   103,   103,   103,     3,     3,     3,
     3,    77,     3,    71,    94,    95,    96,    97,    98,    99,
   133,     3,   135,     3,     3,   138,   139,   140,   141,   142,
   143,   144,   145,   146,    71,     3,   149,   150,   151,   152,
    78,    77,    78,    79,     3,     3,     3,    84,    98,    98,
   116,   117,   118,   119,   120,    98,    98,    71,   171,     3,
   173,   174,    77,    78,    79,    80,    81,    82,    83,   102,
    85,    86,    94,    95,    96,    97,    98,    99,     3,    94,
    95,    96,    97,    98,    99,     3,    35,   153,    76,   202,
   203,     6,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,     3,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     3,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,     5,    85,
    86,     3,     3,     3,     0,   103,     0,    27,    94,    95,
    96,    97,    98,    99,   133,    -1,    -1,    63,    64,    65,
    66,    67,    68,    69,    70,   202,    -1,    -1,    -1,    75,
    -1,    -1,    78,    -1,    -1,    -1,   101,    -1,    84,    -1,
    -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
    77,    78,    79,    80,    81,    82,    83,    -1,    85,    86,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
    97,    98,    99,    71,    72,    73,    74,    -1,    -1,    77,
    78,    79,    80,    81,    82,    83,    -1,    85,    86,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
    98,    99,    72,    73,    74,    -1,    -1,    77,    78,    79,
    80,    81,    82,    83,    -1,    85,    86,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 2:
#line 132 "inform.y"
{ lex_offset = n_strlen(lex_expression); ;
    break;}
case 3:
#line 134 "inform.y"
{
		strid_t f;
		f = n_file_name_or_prompt(fileusage_Data|fileusage_BinaryMode,
					  filemode_Write, lex_tail());
		w_glk_put_buffer_stream(f, (char *) z_memory, total_size);
		glk_stream_close(f, NULL);
	;
    break;}
case 4:
#line 142 "inform.y"
{ parse_new_alias(lex_tail(), FALSE); ;
    break;}
case 5:
#line 144 "inform.y"
{ parse_new_alias(lex_tail(), TRUE); ;
    break;}
case 6:
#line 146 "inform.y"
{ remove_alias(lex_tail()); ;
    break;}
case 7:
#line 148 "inform.y"
{ automap_init(object_count, lex_tail()); ;
    break;}
case 8:
#line 150 "inform.y"
{ inform_help(); ;
    break;}
case 9:
#line 152 "inform.y"
{ op_restart(); exit_debugger = TRUE; read_abort = TRUE;  ;
    break;}
case 10:
#line 154 "inform.y"
{
		if(restoregame()) {
		  exit_debugger = TRUE; read_abort = TRUE;
		  if(zversion <= 3)
		    mop_take_branch();
		  else
		    mop_store_result(2);
		} else {
		  infix_print_string("Restore failed.\n");
		} ;
    break;}
case 11:
#line 165 "inform.y"
{ zword oldop0 = operand[0]; operand[0] = 4; op_output_stream(); operand[0] = oldop0; ;
    break;}
case 12:
#line 167 "inform.y"
{ zword oldop0 = operand[0]; operand[0] = neg(4); op_output_stream(); operand[0] = oldop0; ;
    break;}
case 13:
#line 169 "inform.y"
{ zword oldop0 = operand[0]; operand[0] = 1; op_input_stream(); operand[0] = oldop0; exit_debugger = TRUE; ;
    break;}
case 14:
#line 171 "inform.y"
{ zword oldop0 = operand[0]; operand[0] = 0; op_input_stream(); operand[0] = oldop0; ;
    break;}
case 15:
#line 173 "inform.y"
{ z_close(); glk_exit();	;
    break;}
case 16:
#line 175 "inform.y"
{
		if(restoreundo()) {
		  read_abort = TRUE; exit_debugger = TRUE;
		} else {
		  infix_print_string("No undo slots.\n");
		} ;
    break;}
case 17:
#line 182 "inform.y"
{
		if(restoreredo()) {
		  read_abort = TRUE; exit_debugger = TRUE;
		} else {
		  infix_print_string("No redo slots.\n");
		} ;
    break;}
case 18:
#line 189 "inform.y"
{
		strid_t f;
		f = n_file_name_or_prompt(fileusage_Data|fileusage_BinaryMode,
					  filemode_Read, lex_tail());
		if(f) {
		  kill_infix();
		  init_infix(f);
		} ;
    break;}
case 19:
#line 198 "inform.y"
{ infix_display(yyvsp[0].val);		;
    break;}
case 20:
#line 200 "inform.y"
{ inform_result = yyvsp[0].val;		;
    break;}
case 21:
#line 202 "inform.y"
{ infix_auto_display(lex_tail()); ;
    break;}
case 22:
#line 204 "inform.y"
{ infix_auto_undisplay(yyvsp[0].val.v);	;
    break;}
case 23:
#line 206 "inform.y"
{ infix_set_display_enabled(yyvsp[0].val.v, FALSE); ;
    break;}
case 24:
#line 208 "inform.y"
{ infix_set_display_enabled(yyvsp[0].val.v, TRUE); ;
    break;}
case 25:
#line 210 "inform.y"
{ infix_move(yyvsp[0].val.v, yyvsp[-2].val.v); 	;
    break;}
case 26:
#line 212 "inform.y"
{ infix_object_tree(0);		;
    break;}
case 27:
#line 214 "inform.y"
{ infix_object_tree(yyvsp[0].val.v);	;
    break;}
case 28:
#line 216 "inform.y"
{
		if(lex_expression[lex_offset])
		  infix_object_find(lex_tail());
	;
    break;}
case 29:
#line 221 "inform.y"
{
		z_typed v; v.t = Z_GLOBAL;
		for(v.o = 0; v.o <= 245; v.o++) {
		  const char *name = infix_get_name(v);
		  if(v.o) infix_print_string("; ");
		  if(name) {
		    infix_print_string(name);
		  } else {
		    infix_print_char('G');
		    infix_print_number(v.o);
		  }
		  infix_print_char('=');
		  infix_get_val(&v);
		  infix_print_number(v.v);
		}
		infix_print_char(10);
	;
    break;}
case 30:
#line 239 "inform.y"
{
		z_typed v; v.t = Z_GLOBAL;
		for(v.o = 0; v.o <= 245; v.o++) {
		  infix_get_val(&v);
		  if(v.v == yyvsp[0].val.v) {
		    const char *name = infix_get_name(v);
		    if(name) {
		      infix_print_string(name);
		    } else {
		      infix_print_char('G');
		      infix_print_number(v.o);
		    }
		    infix_print_char(10);
		  }
		} ;
    break;}
case 31:
#line 255 "inform.y"
{ infix_set_attrib(yyvsp[-1].val.v, yyvsp[0].val.v);	;
    break;}
case 32:
#line 257 "inform.y"
{ infix_clear_attrib(yyvsp[-2].val.v, yyvsp[0].val.v); ;
    break;}
case 33:
#line 259 "inform.y"
{ infix_remove(yyvsp[0].val.v);		;
    break;}
case 34:
#line 261 "inform.y"
{ PC=yyvsp[0].pcoffset; exit_debugger = TRUE;	;
    break;}
case 35:
#line 263 "inform.y"
{ set_step(CONT_GO, 1); ;
    break;}
case 36:
#line 265 "inform.y"
{ set_step(CONT_GO, 1); infix_set_ignore(cur_break, yyvsp[0].val.v); ;
    break;}
case 37:
#line 267 "inform.y"
{ set_step(CONT_STEP, 1); ;
    break;}
case 38:
#line 269 "inform.y"
{ set_step(CONT_STEP, yyvsp[0].val.v); ;
    break;}
case 39:
#line 271 "inform.y"
{ set_step(CONT_NEXT, 1); ;
    break;}
case 40:
#line 273 "inform.y"
{ set_step(CONT_NEXT, yyvsp[0].val.v); ;
    break;}
case 41:
#line 275 "inform.y"
{ set_step(CONT_UNTIL, 1); ;
    break;}
case 42:
#line 277 "inform.y"
{ set_step(CONT_STEPI, 1); ;
    break;}
case 43:
#line 279 "inform.y"
{ set_step(CONT_STEPI, yyvsp[0].val.v); ;
    break;}
case 44:
#line 281 "inform.y"
{ set_step(CONT_NEXTI, 1); ;
    break;}
case 45:
#line 283 "inform.y"
{ set_step(CONT_NEXTI, yyvsp[0].val.v); ;
    break;}
case 46:
#line 285 "inform.y"
{ set_step(CONT_FINISH, 1); ;
    break;}
case 47:
#line 287 "inform.y"
{ infix_set_break(yyvsp[0].pcoffset);	;
    break;}
case 48:
#line 289 "inform.y"
{ int n = infix_set_break(yyvsp[-1].pcoffset); infix_set_cond(n, lex_tail()); ;
    break;}
case 49:
#line 291 "inform.y"
{ infix_set_cond(yyvsp[0].val.v, lex_tail()); ;
    break;}
case 50:
#line 293 "inform.y"
{ infix_set_ignore(yyvsp[-1].val.v, yyvsp[0].val.v);	;
    break;}
case 51:
#line 295 "inform.y"
{ infix_delete_breakpoint(yyvsp[0].val.v); ;
    break;}
case 52:
#line 297 "inform.y"
{ infix_show_all_breakpoints(); ;
    break;}
case 53:
#line 299 "inform.y"
{ infix_show_breakpoint(yyvsp[0].val.v);	;
    break;}
case 54:
#line 301 "inform.y"
{ infix_set_break_enabled(yyvsp[0].val.v, FALSE); ;
    break;}
case 55:
#line 303 "inform.y"
{ infix_set_break_enabled(yyvsp[0].val.v, TRUE); ;
    break;}
case 56:
#line 305 "inform.y"
{ infix_print_string("The current source language is \"inform\".\n"); ;
    break;}
case 57:
#line 307 "inform.y"
{ infix_print_string("Current source file is "); infix_print_string(cur_file->filename); infix_print_string("\nContains "); infix_print_number(cur_file->num_lines); infix_print_string(" lines.\nSource language is inform.\n"); ;
    break;}
case 58:
#line 309 "inform.y"
{ infix_print_string("Source files for which symbols have been read in:\n\n"); infix_list_files(); infix_print_char('\n'); ;
    break;}
case 59:
#line 311 "inform.y"
{ show_copying(); ;
    break;}
case 60:
#line 313 "inform.y"
{ show_warranty(); ;
    break;}
case 61:
#line 315 "inform.y"
{ infix_show_frame(infix_selected_frame); ;
    break;}
case 62:
#line 317 "inform.y"
{ infix_select_frame(yyvsp[0].val.v); infix_show_frame(yyvsp[0].val.v); ;
    break;}
case 63:
#line 319 "inform.y"
{ infix_select_frame(yyvsp[0].val.v); ;
    break;}
case 64:
#line 321 "inform.y"
{ infix_select_frame(infix_selected_frame - 1); infix_show_frame(infix_selected_frame); ;
    break;}
case 65:
#line 323 "inform.y"
{ infix_select_frame(infix_selected_frame - yyvsp[0].val.v); infix_show_frame(infix_selected_frame); ;
    break;}
case 66:
#line 325 "inform.y"
{ infix_select_frame(infix_selected_frame - 1); ;
    break;}
case 67:
#line 327 "inform.y"
{ infix_select_frame(infix_selected_frame - yyvsp[0].val.v); ;
    break;}
case 68:
#line 329 "inform.y"
{ infix_select_frame(infix_selected_frame + 1); infix_show_frame(infix_selected_frame); ;
    break;}
case 69:
#line 331 "inform.y"
{ infix_select_frame(infix_selected_frame + yyvsp[0].val.v); infix_show_frame(infix_selected_frame); ;
    break;}
case 70:
#line 333 "inform.y"
{ infix_select_frame(infix_selected_frame + 1); ;
    break;}
case 71:
#line 335 "inform.y"
{ infix_select_frame(infix_selected_frame + yyvsp[0].val.v); ;
    break;}
case 72:
#line 337 "inform.y"
{ infix_backtrace(0, stack_get_depth()); ;
    break;}
case 73:
#line 339 "inform.y"
{ infix_backtrace(stack_get_depth() - yyvsp[0].val.v, yyvsp[0].val.v); ;
    break;}
case 74:
#line 341 "inform.y"
{ infix_backtrace(0, yyvsp[0].val.v); ;
    break;}
case 75:
#line 349 "inform.y"
{ if(yyvsp[0].val.t == Z_ROUTINE) yyval.pcoffset = infix_get_routine_PC(yyvsp[0].val.v); else { infix_location l; infix_decode_fileloc(&l, cur_file->filename, yyvsp[0].val.v); yyval.pcoffset = l.thisPC; } ;
    break;}
case 76:
#line 350 "inform.y"
{ infix_location l; infix_decode_fileloc(&l, cur_file->filename, cur_line + yyvsp[0].val.v); yyval.pcoffset = l.thisPC; ;
    break;}
case 77:
#line 351 "inform.y"
{ infix_location l; infix_decode_fileloc(&l, cur_file->filename, cur_line - yyvsp[0].val.v); yyval.pcoffset = l.thisPC; ;
    break;}
case 78:
#line 352 "inform.y"
{ if(yyvsp[0].val.t == Z_ROUTINE) yyval.pcoffset = UNPACKR(yyvsp[0].val.v); else { infix_location l; infix_decode_fileloc(&l, yyvsp[-2].filenum->filename, yyvsp[0].val.v); yyval.pcoffset = l.thisPC; } ;
    break;}
case 79:
#line 353 "inform.y"
{ yyval.pcoffset = yyvsp[0].val.v;			;
    break;}
case 80:
#line 357 "inform.y"
{
		if(condlist->condfunc(condlist->val, yyvsp[0].val.v) ^ condlist->opposite) {
		   yyval.flag = TRUE;
		   ignoreeffects++;
		} else
		   yyval.flag = FALSE;
	    ;
    break;}
case 81:
#line 364 "inform.y"
{
		if(yyvsp[-2].flag)
		  yyval.flag = TRUE;
		else {
		  if(condlist->condfunc(condlist->val, yyvsp[0].val.v) ^ condlist->opposite) {
		    yyval.flag = TRUE;
		    ignoreeffects++;
		  }
		  else yyval.flag = FALSE;
		} ;
    break;}
case 82:
#line 377 "inform.y"
{ yyval.zlist = NULL; ;
    break;}
case 83:
#line 378 "inform.y"
{ zword_list g; yyval.zlist = yyvsp[0].zlist; g.item = yyvsp[-2].val.v; LEaddm(yyval.zlist, g, n_rmmalloc); ;
    break;}
case 86:
#line 384 "inform.y"
{ yyval.val = yyvsp[0].val;			;
    break;}
case 87:
#line 385 "inform.y"
{ yyval.val = yyvsp[0].val;			;
    break;}
case 88:
#line 390 "inform.y"
{ cond_list newcond; newcond.val = yyvsp[-1].val.v; newcond.condfunc = yyvsp[0].cond.condfunc; newcond.opposite = yyvsp[0].cond.opposite; LEaddm(condlist, newcond, n_rmmalloc); ;
    break;}
case 89:
#line 390 "inform.y"
{ if(yyvsp[0].flag) ignoreeffects--; yyval.val.v = yyvsp[0].flag; yyval.val.t = Z_BOOLEAN; LEremovem(condlist, n_rmfreeone); ;
    break;}
case 90:
#line 394 "inform.y"
{ yyval.val = yyvsp[0].val;				;
    break;}
case 91:
#line 396 "inform.y"
{ yyval.val.v = 0; yyval.val.t = Z_BOOLEAN;		;
    break;}
case 92:
#line 398 "inform.y"
{ yyval.val.v = 1; yyval.val.t = Z_BOOLEAN;		;
    break;}
case 93:
#line 400 "inform.y"
{ yyval.val.v = 0; yyval.val.t = Z_OBJECT;		;
    break;}
case 94:
#line 403 "inform.y"
{ yyval.val = yyvsp[0].val; infix_assign(&yyvsp[-2].val, yyvsp[0].val.v);	;
    break;}
case 95:
#line 406 "inform.y"
{ yyval.val.v = infix_parent(yyvsp[-1].val.v); yyval.val.t = Z_OBJECT; ;
    break;}
case 96:
#line 408 "inform.y"
{ yyval.val.v = infix_child(yyvsp[-1].val.v); yyval.val.t = Z_OBJECT; ;
    break;}
case 97:
#line 410 "inform.y"
{ yyval.val.v = infix_sibling(yyvsp[-1].val.v); yyval.val.t = Z_OBJECT; ;
    break;}
case 98:
#line 412 "inform.y"
{ int n = 0; zword o = infix_child(yyvsp[-1].val.v); while(o) { n++; o = infix_sibling(o); } yyval.val.v = n; yyval.val.t = Z_NUMBER; ;
    break;}
case 99:
#line 415 "inform.y"
{
		  if(!ignoreeffects) {
		    yyval.val.v = z_random(yyvsp[-1].val.v);
		    yyval.val.t = Z_NUMBER;
		  } else {
		    yyval.val.v = 0;
		    yyval.val.t = Z_UNKNOWN;
		  }
		;
    break;}
case 100:
#line 425 "inform.y"
{
		zword locals[16];
		int i = 0;
		zword_list *p;
		if(!ignoreeffects) {
		  for(p = yyvsp[-1].zlist; p && i < 16; p=p->next) {
		    locals[i++] = p->item;
		  }
		  mop_call(yyvsp[-3].val.v, i, locals, -2);
		  decode();
		  exit_decoder = FALSE;
		  yyval.val.v = time_ret; yyval.val.t = Z_UNKNOWN;
		} else {
		  yyval.val.v = 0; yyval.val.t = Z_UNKNOWN;
		}
	      ;
    break;}
case 101:
#line 442 "inform.y"
{ if(yyvsp[-1].val.v == 0) ignoreeffects++; ;
    break;}
case 102:
#line 443 "inform.y"
{ if(yyvsp[-3].val.v == 0) ignoreeffects--; yyval.val = z_t(yyvsp[-3].val, yyvsp[0].val, yyvsp[-3].val.v && yyvsp[0].val.v);	;
    break;}
case 103:
#line 444 "inform.y"
{ if(yyvsp[-1].val.v != 0) ignoreeffects++; ;
    break;}
case 104:
#line 445 "inform.y"
{ if(yyvsp[-3].val.v != 0) ignoreeffects--; yyval.val = z_t(yyvsp[-3].val, yyvsp[0].val, yyvsp[-3].val.v || yyvsp[0].val.v);	;
    break;}
case 105:
#line 447 "inform.y"
{ yyval.val.v = !(yyvsp[0].val.v); yyval.val.t = Z_NUMBER;	;
    break;}
case 106:
#line 450 "inform.y"
{ yyval.val = z_t(yyvsp[-2].val, yyvsp[0].val, yyvsp[-2].val.v + yyvsp[0].val.v);	;
    break;}
case 107:
#line 452 "inform.y"
{ yyval.val = z_t(yyvsp[-2].val, yyvsp[0].val, yyvsp[-2].val.v + neg(yyvsp[0].val.v));	;
    break;}
case 108:
#line 454 "inform.y"
{ yyval.val = z_t(yyvsp[-2].val, yyvsp[0].val, z_mult(yyvsp[-2].val.v, yyvsp[0].val.v));	;
    break;}
case 109:
#line 456 "inform.y"
{ yyval.val = z_t(yyvsp[-2].val, yyvsp[0].val, z_div(yyvsp[-2].val.v, yyvsp[0].val.v));	;
    break;}
case 110:
#line 458 "inform.y"
{ yyval.val = z_t(yyvsp[-2].val, yyvsp[0].val, z_mod(yyvsp[-2].val.v, yyvsp[0].val.v));	;
    break;}
case 111:
#line 460 "inform.y"
{ yyval.val = z_t(yyvsp[-2].val, yyvsp[0].val, yyvsp[-2].val.v & yyvsp[0].val.v);	;
    break;}
case 112:
#line 462 "inform.y"
{ yyval.val = z_t(yyvsp[-2].val, yyvsp[0].val, yyvsp[-2].val.v | yyvsp[0].val.v);	;
    break;}
case 113:
#line 464 "inform.y"
{ yyval.val = z_t(yyvsp[0].val, yyvsp[0].val, ~yyvsp[0].val.v);		;
    break;}
case 114:
#line 467 "inform.y"
{ yyval.val.t = Z_BYTEARRAY; yyval.val.o = yyvsp[-2].val.v; yyval.val.p = yyvsp[0].val.v; infix_get_val(&yyval.val); ;
    break;}
case 115:
#line 469 "inform.y"
{ yyval.val.t = Z_WORDARRAY; yyval.val.o = yyvsp[-2].val.v; yyval.val.p = yyvsp[0].val.v; infix_get_val(&yyval.val);	;
    break;}
case 116:
#line 472 "inform.y"
{ yyval.val = z_t(yyvsp[0].val, yyvsp[0].val, neg(yyvsp[0].val.v));		;
    break;}
case 117:
#line 475 "inform.y"
{ if(!ignoreeffects) infix_assign(&yyvsp[0].val, ARITHMASK(yyvsp[0].val.v + 1)); yyval.val = yyvsp[0].val; ;
    break;}
case 118:
#line 477 "inform.y"
{ yyval.val = yyvsp[-1].val; if(!ignoreeffects) infix_assign(&yyvsp[-1].val, ARITHMASK(yyvsp[-1].val.v + 1)); ;
    break;}
case 119:
#line 479 "inform.y"
{ if(!ignoreeffects) infix_assign(&yyvsp[0].val, ARITHMASK(yyvsp[0].val.v + neg(1))); yyval.val = yyvsp[0].val; ;
    break;}
case 120:
#line 481 "inform.y"
{ yyval.val = yyvsp[-1].val; if(!ignoreeffects) infix_assign(&yyvsp[-1].val, ARITHMASK(yyvsp[-1].val.v + neg(1))); ;
    break;}
case 121:
#line 484 "inform.y"
{ zword len; yyval.val.v = infix_get_proptable(yyvsp[-2].val.v, yyvsp[0].val.v, &len); yyval.val.t = Z_NUMBER; ;
    break;}
case 122:
#line 486 "inform.y"
{ infix_get_proptable(yyvsp[-2].val.v, yyvsp[0].val.v, &yyval.val.v); yyval.val.t = Z_NUMBER; ;
    break;}
case 123:
#line 489 "inform.y"
{ yyval.val.t = Z_OBJPROP; yyval.val.o = yyvsp[-2].val.v; yyval.val.p = yyvsp[0].val.v; infix_get_val(&yyval.val); ;
    break;}
case 124:
#line 497 "inform.y"
{ yyval.val.v = yyvsp[0].val.v; yyval.val.t = Z_NUMBER;		;
    break;}
case 125:
#line 499 "inform.y"
{ yyval.val.v = yyvsp[0].val.v; yyval.val.t = Z_OBJECT;		;
    break;}
case 126:
#line 501 "inform.y"
{ yyval.val.v = yyvsp[0].val.v; yyval.val.t = Z_ROUTINE;	;
    break;}
case 127:
#line 503 "inform.y"
{ yyval.val.v = yyvsp[0].val.v; yyval.val.t = Z_STRING;		;
    break;}
case 128:
#line 505 "inform.y"
{ yyval.val.t = Z_WORDARRAY; yyval.val.o = z_globaltable; yyval.val.p = yyvsp[0].val.v; infix_get_val(&yyval.val); ;
    break;}
case 129:
#line 507 "inform.y"
{ yyval.val.t = Z_LOCAL; yyval.val.o = infix_selected_frame; yyval.val.p = yyvsp[0].val.v; infix_get_val(&yyval.val); ;
    break;}
case 130:
#line 509 "inform.y"
{ yyval.val = yyvsp[-1].val;				;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 513 "inform.y"


#if 0
{ /* fanagling to get emacs indentation sane */
int foo;
#endif

static z_typed z_t(z_typed a, z_typed b, zword v)
{
  z_typed r;
  r.v = ARITHMASK(v);
  if(a.t == Z_NUMBER && b.t == Z_NUMBER)
    r.t = Z_NUMBER;
  else
    r.t = Z_UNKNOWN;
  return r;
}



typedef struct {
  int token;
  const char *name;
} name_token;

static name_token infix_operators[] = {
  { ANDAND,     "&&" },
  { OROR,       "||" },
  { NOTNOT,     "~~" },
  { BYTEARRAY,  "->" },
  { WORDARRAY,  "-->" },
  { NUMBER,     "(number)" },
  { OBJECT,     "(object)" },
  { ROUTINE,    "(routine)" },
  { STRING,     "(string)" },
  { GLOBAL,     "(global)" },
  { LOCAL,      "(local)" },
  { INCREMENT,  "++" },
  { DECREMENT,  "--" },
  { SUPERCLASS, "::" }
};


static name_token infix_keywords[] = {
  { TO,         "to" },
  { IF,         "if" },
  { OR,         "or" },
  { BTRUE,      "true" },
  { BFALSE,     "false" },
  { NOTHING,    "nothing" },
  { PARENT,     "parent" },
  { CHILD,      "child" },
  { SIBLING,    "sibling" },
  { RANDOM,     "random" },
  { CHILDREN,   "children" }
};


/* These are only valid as the first token in an expression.  A single space
   matches at least one typed whitespace character */
static name_token infix_commands[] = {
  { '#',          "#" },
  { HELP,         "help" },
  { ALIAS,        "alias" },
  { RALIAS,       "ralias" },
  { UNALIAS,      "unalias" },
  { DUMPMEM,      "dumpmem" },
  { AUTOMAP,      "automap" },
  { UNDO,         "undo" },
  { REDO,         "redo" },
  { QUIT,         "quit" },
  { RESTORE,      "restore" },
  { RESTART,      "restart" },
  { RESTART,      "run" },
  { RECORDON,	  "recording on" },
  { RECORDOFF,    "recording off" },
  { REPLAY,       "replay" },
  { REPLAYOFF,    "replay off" },
  { SYMBOL_FILE,  "symbol-file" },
  { PRINT,        "print" },
  { PRINT,        "p" },
  { PRINT,        "call" },  /* No void functions in inform */
  { SET,          "set" },
  { MOVE,         "move" },
  { OBJECT_TREE,  "object-tree" },
  { OBJECT_TREE,  "tree" },
  { FIND,         "find" },
  { REMOVE,       "remove" },
  { GIVE,         "give" },
  { LIST_GLOBALS, "globals" },
  { JUMP,         "jump" },
  { CONT,         "continue" },
  { CONT,         "c" },
  { CONT,         "fg" },
  { STEP,         "step" },
  { STEP,         "s" },
  { NEXT,         "next" },
  { NEXT,         "n" },
  { STEPI,        "stepi" },
  { STEPI,        "si" },
  { NEXTI,        "nexti" },
  { NEXTI,        "ni" },
  { UNTIL,        "until" },
  { UNTIL,        "u" },
  { FINISH,       "finish" },
  { BREAK,        "break" },
  { DELETE,       "delete" },
  { DELETE,       "d" },
  { DELETE,       "delete breakpoints" },
  { COND,         "condition" },
  { IGNORE,       "ignore" },
  { FRAME,        "frame" },
  { FRAME,        "f" },
  { SELECT_FRAME, "select-frame" },
  { UP_FRAME,     "up" },
  { DOWN_FRAME,   "down" },
  { DOWN_FRAME,   "do" },
  { UP_SILENTLY,  "up-silently" },
  { DOWN_SILENTLY,"down-silently" },
  { BREAKPOINTS,  "info breakpoints" },
  { BREAKPOINTS,  "info watchpoints" },
  { BREAKPOINTS,  "info break" },
  { DISABLE_BREAK,"disable" },
  { DISABLE_BREAK,"disable breakpoints" },
  { DISABLE_BREAK,"dis" },
  { DISABLE_BREAK,"dis breakpoints" },
  { ENABLE_BREAK, "enable" },
  { ENABLE_BREAK, "enable breakpoints" },
  { LANGUAGE,     "show language" },
  { INFOSOURCE,   "info source" },
  { INFOSOURCES,  "info sources" },
  { COPYING,      "show copying" },
  { WARRANTY,     "show warranty" },
  { BACKTRACE,    "backtrace" },
  { BACKTRACE,    "bt" },
  { BACKTRACE,    "where" },
  { BACKTRACE,    "info stack" },
  { BACKTRACE,    "info s" },
  { DISPLAY,      "display" },
  { UNDISPLAY,    "undisplay" },
  { UNDISPLAY,    "delete display" },
  { DISABLE_DISPLAY,"disable display" },
  { DISABLE_DISPLAY,"dis display" },
  { ENABLE_DISPLAY,"enable display" }
};

#include "dbg_help.h"

static BOOL z_isequal(zword a, zword b)
{
  return (a == b);
}

static BOOL z_isgreat(zword a, zword b)
{
  return is_greaterthan(a, b);
}

static BOOL z_isless(zword a, zword b)
{
  return is_lessthan(a, b);
}

static BOOL infix_provides(zword o, zword p)
{
  zword len;
  return (infix_get_proptable(o, p, &len) != 0);
}

static BOOL infix_in(zword a, zword b)
{
  return infix_parent(a) == b;
}

typedef struct {
  const char *name;
  BOOL (*condfunc)(zword a, zword b);
  BOOL opposite;
} condition;

condition conditionlist[] = {
  { "==",      z_isequal,         FALSE },
  { "~=",      z_isequal,         TRUE },
  { ">",       z_isgreat,         FALSE },
  { "<",       z_isless,          FALSE },
  { "<=",      z_isgreat,         TRUE },
  { ">=",      z_isless,          TRUE },
  { "has",     infix_test_attrib, FALSE },
  { "hasnt",   infix_test_attrib, TRUE },
  { "in",      infix_in,          FALSE },
  { "notin",   infix_in,          TRUE },
/*{ "ofclass", infix_ofclass,     FALSE },*/
  { "provides",infix_provides,    FALSE }
};


static BOOL is_command_identifier(char c)
{
  return isalpha(c) || (c == '-');
}

static BOOL is_identifier(char c)
{
  return isalpha(c) || isdigit(c) || (c == '_');
}

static BOOL is_longer_identifier(char c)
{
  return isalpha(c) || isdigit(c) || (c == '_') || (c == '.') || (c == ':');
}

static int grab_number(z_typed *val)
{
  int len = 0;
  char *endptr;
  char c = lex_expression[lex_offset + len];
  int base = 10;
  long int num;

  /* Don't handle negativity here */
  if(c == '-' || c == '+')
    return 0;
  
  if(c == '$') {
    len++;
    base = 16;
    c = lex_expression[lex_offset + len];
    if(c == '$') {
      len++;
      base = 2;
      c = lex_expression[lex_offset + len];
    }
  }
  
  num = n_strtol(lex_expression + lex_offset + len, &endptr, base);

  if(endptr != lex_expression + lex_offset) {
    len += endptr - lex_expression - lex_offset;
    val->v = num;
    val->t = Z_NUMBER;
    return len;
  }
  return 0;
}


typedef enum { match_None, match_Partial, match_Complete } match_type;

static match_type command_matches(const char *command, const char *expression,
				  unsigned *matchedlen)
{
  unsigned c, e;
  e = 0;

  for(c = 0; command[c]; c++) {
    if(command[c] != expression[e]) {
      if(!is_command_identifier(expression[e])) {
	*matchedlen = e;
	return match_Partial;
      }
      return match_None;
    }

    e++;
    
    if(command[c] == ' ') {
      while(expression[e] == ' ')
	e++;
    }
  }

  if(!is_command_identifier(expression[e])) {
    *matchedlen = e;
    return match_Complete; 
  }

  return match_None;
}


static int grab_command(void)
{
  unsigned i;
  unsigned len;

  unsigned best;
  match_type best_match = match_None;
  unsigned best_len = 0;
  BOOL found = FALSE;
  BOOL ambig = FALSE;

  while(isspace(lex_expression[lex_offset]))
    lex_offset++;

  for(i = 0; i < sizeof(infix_commands) / sizeof(*infix_commands); i++) {
    switch(command_matches(infix_commands[i].name, lex_expression + lex_offset, &len)) {
    case match_Complete:
      if(len > best_len || best_match != match_Complete) {
	best = i;
	best_match = match_Complete;
	best_len = len;
	found = TRUE;
      }
      break;

    case match_Partial:
      if(best_match != match_Complete) {
	if(found)
	  ambig = TRUE;
	best = i;
	best_match = match_Partial;
	best_len = len;
	found = TRUE;
      }

    case match_None:
      ;
    }
  }

  if(ambig && best_match != match_Complete) {
    infix_print_string("Ambiguous command.\n");
    return 0;
  }

  if(found) {
    lex_offset += best_len;
    return infix_commands[best].token;
  }

  infix_print_string("Undefined command.\n");
  return 0;
}


static void inform_help(void)
{
  int command;
  unsigned i;
  BOOL is_command = FALSE;
  
  for(i = lex_offset; lex_expression[i]; i++)
    if(!isspace(lex_expression[i]))
      is_command = TRUE;

  if(!is_command) {
    infix_print_string("Help is available on the following commands:\n");
    for(i = 0; i < sizeof(command_help) / sizeof(*command_help); i++) {
      unsigned j;
      for(j = 0; j < sizeof(infix_commands) / sizeof(*infix_commands); j++)
	if(command_help[i].token == infix_commands[j].token) {
	  infix_print_char('\'');
	  infix_print_string(infix_commands[j].name);
	  infix_print_char('\'');
	  break;
	}
      infix_print_char(' ');
    }
    infix_print_string("\n");
    return;
  }
  
  command = grab_command();
  if(command) {
    for(i = 0; i < sizeof(command_help) / sizeof(*command_help); i++) {
      if(command_help[i].token == command) {
	infix_print_string(command_help[i].name);
	infix_print_char(10);
	return;
      }
    }
    infix_print_string("No help available for that command.\n");
  }
}


void process_debug_command(const char *buffer)
{
#ifdef YYDEBUG
  yydebug = 1;
#endif
  lex_expression = buffer;
  lex_offset = 0;
  ignoreeffects = 0;
  yyparse();
  n_rmfree();
}

BOOL exp_has_locals(const char *exp)
{
  return FALSE;
}

z_typed evaluate_expression(const char *exp, unsigned frame)
{
  unsigned old_frame = infix_selected_frame;
  char *new_exp = (char *) n_malloc(n_strlen(exp) + 5);
  n_strcpy(new_exp, "set ");
  n_strcat(new_exp, exp);

  infix_selected_frame = frame;
  process_debug_command(new_exp);
  infix_selected_frame = old_frame;

  n_free(new_exp);

  return inform_result;
}

static void yyerror(const char *s)
{
  infix_print_string(s);
  infix_print_char(10);
}

static int yylex(void)
{
  unsigned i, len, longer;
  BOOL check_command = FALSE;

  if(lex_offset == 0)
    check_command = TRUE;

  while(isspace(lex_expression[lex_offset]))
    lex_offset++;

  if(check_command) {
    return grab_command();
  }

  if((len = grab_number(&yylval.val)) != 0) {
    lex_offset += len;
    return NUM;
  }

  for(i = 0; i < sizeof(infix_operators) / sizeof(*infix_operators); i++) {
    if(n_strncmp(infix_operators[i].name, lex_expression + lex_offset,
	       n_strlen(infix_operators[i].name)) == 0) {
      lex_offset += n_strlen(infix_operators[i].name);
      return infix_operators[i].token;
    }
  }

  for(i = 0; i < sizeof(conditionlist) / sizeof(*conditionlist); i++) {
    len = n_strlen(conditionlist[i].name);
    if(len
       && n_strncmp(conditionlist[i].name,
		   lex_expression + lex_offset, len) == 0
       && !(is_identifier(conditionlist[i].name[len-1])
	    && is_identifier(lex_expression[lex_offset + len]))) {

      lex_offset += len;
      yylval.cond.condfunc = conditionlist[i].condfunc;
      yylval.cond.opposite = conditionlist[i].opposite;
      return CONDITION;
    }
  }

  if((len = infix_find_file(&yylval.filenum, lex_expression + lex_offset)) != 0) {
    lex_offset += len;
    return DFILE;
  }


  for(len = 0; is_identifier(lex_expression[lex_offset + len]); len++)
    ;

  if(!len)
    return lex_expression[lex_offset++];

  for(i = 0; i < sizeof(infix_keywords) / sizeof(*infix_keywords); i++) {
    if(n_strmatch(infix_keywords[i].name, lex_expression + lex_offset, len)) {
      lex_offset += len;
      return infix_keywords[i].token;
    }
  }

  for(longer = len; is_longer_identifier(lex_expression[lex_offset + longer]); longer++)
    ;

  if(infix_find_symbol(&yylval.val, lex_expression + lex_offset, longer)) {
    lex_offset += longer;
    return NUM;
  }

  if(infix_find_symbol(&yylval.val, lex_expression + lex_offset, len)) {
    lex_offset += len;
    return NUM;
  }

  infix_print_string("Unknown identifier \"");
  for(i = 0; i < len; i++)
    infix_print_char(lex_expression[lex_offset + i]);
  infix_print_string("\"\n");

  return 0;
}

#endif /* DEBUGGING */
