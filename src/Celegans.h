/* =============================================================
The MIT License (MIT)

Copyright (c) 2015 Carlo Meroni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
================================================================= */

////////////////////////////////////////////////////////////
///	HEADER
////////////////////////////////////////////////////////////
#ifndef C_ELEGANS_H
#define C_ELEGANS_H

////////////////////////////////////////////////////////////
///	NEURON IDS DEFINES
////////////////////////////////////////////////////////////
#define	ADAL	0
#define	ADAR	1
#define	ADEL	2
#define	ADER	3
#define	ADFL	4
#define	ADFR	5
#define	ADLL	6
#define	ADLR	7
#define	AFDL	8
#define	AFDR	9
#define	AIAL	10
#define	AIAR	11
#define	AIBL	12
#define	AIBR	13
#define	AIML	14
#define	AIMR	15
#define	AINL	16
#define	AINR	17
#define	AIYL	18
#define	AIYR	19
#define	AIZL	20
#define	AIZR	21
#define	ALA		22
#define	ALML	23
#define	ALMR	24
#define	ALNL	25
#define	ALNR	26
#define	AQR		27
#define	AS1		28
#define	AS10	29
#define	AS11	30
#define	AS2		31
#define	AS3		32
#define	AS4		33
#define	AS5		34
#define	AS6		35
#define	AS7		36
#define	AS8		37
#define	AS9		38
#define	ASEL	39
#define	ASER	40
#define	ASGL	41
#define	ASGR	42
#define	ASHL	43
#define	ASHR	44
#define	ASIL	45
#define	ASIR	46
#define	ASJL	47
#define	ASJR	48
#define	ASKL	49
#define	ASKR	50
#define	AUAL	51
#define	AUAR	52
#define	AVAL	53
#define	AVAR	54
#define	AVBL	55
#define	AVBR	56
#define	AVDL	57
#define	AVDR	58
#define	AVEL	59
#define	AVER	60
#define	AVFL	61
#define	AVFR	62
#define	AVG		63
#define	AVHL	64
#define	AVHR	65
#define	AVJL	66
#define	AVJR	67
#define	AVKL	68
#define	AVKR	69
#define	AVL		70
#define	AVM		71
#define	AWAL	72
#define	AWAR	73
#define	AWBL	74
#define	AWBR	75
#define	AWCL	76
#define	AWCR	77
#define	BAGL	78
#define	BAGR	79
#define	BDUL	80
#define	BDUR	81
#define	CEPDL	82
#define	CEPDR	83
#define	CEPVL	84
#define	CEPVR	85
#define	DA1		86
#define	DA2		87
#define	DA3		88
#define	DA4		89
#define	DA5		90
#define	DA6		91
#define	DA7		92
#define	DA8		93
#define	DA9		94
#define	DB1		95
#define	DB2		96
#define	DB3		97
#define	DB4		98
#define	DB5		99
#define	DB6		100
#define	DB7		101
#define	DD1		102
#define	DD2		103
#define	DD3		104
#define	DD4		105
#define	DD5		106
#define	DD6		107
#define	DVA		108
#define	DVB		109
#define	DVC		110
#define	FLPL	111
#define	FLPR	112
#define	HSNL	113
#define	HSNR	114
#define	I1L		115
#define	I1R		116
#define	I2L		117
#define	I2R		118
#define	I3		119
#define	I4		120
#define	I5		121
#define	I6		122
#define	IL1DL	123
#define	IL1DR	124
#define	IL1L	125
#define	IL1R	126
#define	IL1VL	127
#define	IL1VR	128
#define	IL2DL	129
#define	IL2DR	130
#define	IL2L	131
#define	IL2R	132
#define	IL2VL	133
#define	IL2VR	134
#define	LUAL	135
#define	LUAR	136
#define	M1		137
#define	M2L		138
#define	M2R		139
#define	M3L		140
#define	M3R		141
#define	M4		142
#define	M5		143
#define	MCL		144
#define	MCR		145
#define	MI		146
#define	NSML	147
#define	NSMR	148
#define	OLLL	149
#define	OLLR	150
#define	OLQDL	151
#define	OLQDR	152
#define	OLQVL	153
#define	OLQVR	154
#define	PDA		155
#define	PDB		156
#define	PDEL	157
#define	PDER	158
#define	PHAL	159
#define	PHAR	160
#define	PHBL	161
#define	PHBR	162
#define	PHCL	163
#define	PHCR	164
#define	PLML	165
#define	PLMR	166
#define	PLNL	167
#define	PLNR	168
#define	PQR		169
#define	PVCL	170
#define	PVCR	171
#define	PVDL	172
#define	PVDR	173
#define	PVM		174
#define	PVNL	175
#define	PVNR	176
#define	PVPL	177
#define	PVPR	178
#define	PVQL	179
#define	PVQR	180
#define	PVR		181
#define	PVT		182
#define	PVWL	183
#define	PVWR	184
#define	RIAL	185
#define	RIAR	186
#define	RIBL	187
#define	RIBR	188
#define	RICL	189
#define	RICR	190
#define	RID		191
#define	RIFL	192
#define	RIFR	193
#define	RIGL	194
#define	RIGR	195
#define	RIH		196
#define	RIML	197
#define	RIMR	198
#define	RIPL	199
#define	RIPR	200
#define	RIR		201
#define	RIS		202
#define	RIVL	203
#define	RIVR	204
#define	RMDDL	205
#define	RMDDR	206
#define	RMDL	207
#define	RMDR	208
#define	RMDVL	209
#define	RMDVR	210
#define	RMED	211
#define	RMEL	212
#define	RMER	213
#define	RMEV	214
#define	RMFL	215
#define	RMFR	216
#define	RMGL	217
#define	RMGR	218
#define	RMHL	219
#define	RMHR	220
#define	SAADL	221
#define	SAADR	222
#define	SAAVL	223
#define	SAAVR	224
#define	SABD	225
#define	SABVL	226
#define	SABVR	227
#define	SDQL	228
#define	SDQR	229
#define	SIADL	230
#define	SIADR	231
#define	SIAVL	232
#define	SIAVR	233
#define	SIBDL	234
#define	SIBDR	235
#define	SIBVL	236
#define	SIBVR	237
#define	SMBDL	238
#define	SMBDR	239
#define	SMBVL	240
#define	SMBVR	241
#define	SMDDL	242
#define	SMDDR	243
#define	SMDVL	244
#define	SMDVR	245
#define	URADL	246
#define	URADR	247
#define	URAVL	248
#define	URAVR	249
#define	URBL	250
#define	URBR	251
#define	URXL	252
#define	URXR	253
#define	URYDL	254
#define	URYDR	255
#define	URYVL	256
#define	URYVR	257
#define	VA1		258
#define	VA10	259
#define	VA11	260
#define	VA12	261
#define	VA2		262
#define	VA3		263
#define	VA4		264
#define	VA5		265
#define	VA6		266
#define	VA7		267
#define	VA8		268
#define	VA9		269
#define	VB1		270
#define	VB10	271
#define	VB11	272
#define	VB2		273
#define	VB3		274
#define	VB4		275
#define	VB5		276
#define	VB6		277
#define	VB7		278
#define	VB8		279
#define	VB9		280
#define	VC1		281
#define	VC2		282
#define	VC3		283
#define	VC4		284
#define	VC5		285
#define	VC6		286
#define	VD1		287
#define	VD10	288
#define	VD11	289
#define	VD12	290
#define	VD13	291
#define	VD2		292
#define	VD3		293
#define	VD4		294
#define	VD5		295
#define	VD6		296
#define	VD7		297
#define	VD8		298
#define	VD9		299

#define NEURON_START 0
#define NEURON_END 300

////////////////////////////////////////////////////////////
///	MUSCLE IDS DEFINES
////////////////////////////////////////////////////////////
#define MDL01 300
#define MDL02 301
#define MDL03 302
#define MDL04 303
#define MDL05 304
#define MDL06 305
#define MDL07 306 
#define MDL08 307
#define MDL09 308
#define MDL10 309
#define	MDL11 310
#define MDL12 311
#define MDL13 312
#define MDL14 313
#define MDL15 314
#define MDL16 315
#define MDL17 316
#define MDL18 317
#define MDL19 318
#define MDL20 319
#define MDL21 320
#define MDL22 321
#define MDL23 322
#define MDL24 323
#define MVL01 324
#define MVL02 325
#define MVL03 326
#define MVL04 327
#define MVL05 328
#define MVL06 329
#define MVL07 330
#define MVL08 331
#define MVL09 332
#define MVL10 333
#define MVL11 334
#define MVL12 335
#define MVL13 336
#define MVL14 337
#define MVL15 338
#define MVL16 339
#define MVL17 340
#define MVL18 341
#define MVL19 342
#define MVL20 343
#define MVL21 344
#define MVL22 345
#define MVL23 346

#define MUSCLE_LEFT_START 300
#define MUSCLE_LEFT_MID 324
#define MUSCLE_LEFT_END 347

#define MDR01 347
#define MDR02 348
#define MDR03 349
#define MDR04 350
#define MDR05 351
#define MDR06 352
#define MDR07 353
#define MDR08 354
#define MDR09 355
#define MDR10 356
#define MDR11 357
#define MDR12 358
#define MDR13 359
#define MDR14 360
#define MDR15 361
#define MDR16 362
#define MDR17 363
#define MDR18 364
#define MDR19 365
#define MDR20 366
#define MDR21 367
#define MDR22 368
#define MDR23 369
#define MDR24 370
#define MVR01 371
#define MVR02 372
#define MVR03 373
#define MVR04 374
#define MVR05 375
#define MVR06 376
#define MVR07 377
#define MVR08 378
#define MVR09 379
#define MVR10 380
#define MVR11 381
#define MVR12 382
#define MVR13 383
#define MVR14 384
#define MVR15 385
#define MVR16 386
#define MVR17 387
#define MVR18 388
#define MVR19 389
#define MVR20 390
#define MVR21 391
#define MVR22 392
#define MVR23 393
#define MVR24 394

#define MUSCLE_RIGHT_START 347
#define MUSCLE_RIGHT_MID 371
#define MUSCLE_RIGHT_END 395

#define MANAL 395
#define MVULVA 396

#define BRAIN_SIZE 397

//Brain forward declaration
typedef struct brain brain;

////////////////////////////////////////////////////////////
/// \brief	Create a C. elegans brain	
///
////////////////////////////////////////////////////////////
brain* Celegans_brain_init();

////////////////////////////////////////////////////////////
/// \brief	Destroy a C. elegans brain	
///
////////////////////////////////////////////////////////////
void Celegans_brain_free(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Update the brain states	
///
////////////////////////////////////////////////////////////
void Celegans_brain_update(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Tell a neuron to fire by passing the neuron id	
///
////////////////////////////////////////////////////////////
void Celegans_brain_fire(brain* b, int neuron_id);

////////////////////////////////////////////////////////////
/// \brief	Check if a neuron have just fired	
///
////////////////////////////////////////////////////////////
int Celegans_brain_fired(brain* b, int neuron_id);

////////////////////////////////////////////////////////////
/// \brief	Give food 	
///
////////////////////////////////////////////////////////////
void Celegans_brain_givefood(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Touch the worm nose	
///
////////////////////////////////////////////////////////////
void Celegans_brain_touchnose(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Anterior touch
///
////////////////////////////////////////////////////////////
void Celegans_brain_touchanterior(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Posterior touch
///
////////////////////////////////////////////////////////////
void Celegans_brain_touchposterior(brain* b);

#endif //C_ELEGANS_H
