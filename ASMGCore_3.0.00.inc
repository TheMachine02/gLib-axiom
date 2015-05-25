#ifndef	__ASMGCoreGuard__
#define	__ASMGcoreGuard__

.nolist
#include	"ti83plus.inc"
#include	"Axe.inc"
.list

#define	gTRUE			$FF
#define	gFALSE		$00
#define	true			$FF
#define	false			$00
#define	gDEFAULT		$FFFF

#define	gVERSION		$3000
#define	gEXTENSION		false

#ifndef	gLIBBUFFER
	#define gLIBBUFFER	saveSScreen
#endif

#define	gMacroSDiv16	ld a,l \ sra h \ rra \ sra h \ rra \ sra h \ rra \ sra h \ rra \ ld l, a

#ifdef	gCOMPILE_AXM

;system
sub_gInit		   = 	sub_Axiom1
sub_gEnable	   = 	sub_Axiom2
sub_gDisable	   = 	sub_Axiom3
sub_gFastMath	   = 	sub_Axiom4
;matrix
sub_gLoadIdentity  = 	sub_Axiom5
sub_gLoadScale	   = 	sub_Axiom6
sub_gPushMatrix	   = 	sub_Axiom7
sub_gPopMatrix	   = 	sub_Axiom8
sub_gAngle		   = 	sub_Axiom9
sub_gTranslate	   = 	sub_Axiom10
sub_gTranspose	   = 	sub_Axiom11
;transform
sub_gRotate	   = 	sub_Axiom12
sub_gProject	   = 	sub_Axiom13
sub_fast_gRotate   = 	sub_Axiom14
sub_fast_gProject  = 	sub_Axiom15
;other
sub_gGetkey	   = 	sub_Axiom16
;shader
sub_gVertexShader  = 	sub_Axiom17
sub_gGeomShader	   =	sub_Axiom18
sub_gIn		   =	sub_Axiom19
sub_gOut		   =	sub_Axiom20
sub_gEndPrimitive  =	sub_Axiom21
;vertex array
sub_gGenVBO	   = 	sub_Axiom22
sub_gVBOParam	   =	sub_Axiom23
sub_gVBOUpdate	   =	sub_Axiom24
sub_gVBOPoint	   =	sub_Axiom25
sub_gVBOVertex	   =	sub_Axiom26
sub_gVBOData	   = 	sub_Axiom27
sub_gVBOGetData	   =	sub_Axiom28
;cliping
sub_gClip3D	   =	sub_Axiom29
sub_gCLine		   =	sub_Axiom30
sub_gInFrustrum	   =	sub_Axiom31
sub_gClipPolygon   =	sub_Axiom32

#endif

;poygons
#define	gPOINT		$0001
#define	gLINE			$0002
#define	gTRIANGLE		$0003
#define	gQUADRI		$0004
#define	gLINEFAN		$0102
#define	gTRIANGLEFAN	$0103
#define	gBCULL		%00000001	;gEnable
#define	gSHILOUETTE	%00000010	;gEnable

;Vertex array
#define	gVERTEX_ARRAY	%0001
#define	gNORMAL_ARRAY	%0010
#define	gTEXCOORD_ARRAY	%0100
#define	gCOLOR_ARRAY	%1000

;Texture
#define	gTEXTURE		%00000100	;gEnable
#define	gACTIVE_TEXT	$0001	
#define	gSPHERE_MAP	$0002

;Stencil
#define	gSTENCIL		%00001000	;gEnable
#define	gMARKPASSED	$0000
#define	gMARKFAILED	$0000
#define	gALWAYS		$FFFF
#define	gNEVER		$0000

;Parameters
#define	gFLAGS		asm_Flag2
#define	gFAST_MATH		false

;Lightning
#define	gLIGHTING		%00010000	;gEnable
#define	gSPOT			%01
#define	gAMBIENT		%10
#define	gDIRECTIONAL	%11
#define	gFLAT			$0000
#define	gPHONG		$0001

;Light Parameters
#define	gTYPE			$0
#define	gCUTOFF		$1
#define	gEXPONENT		$2
#define	gDIRECTION		$3
#define	gPOSITION		$6
#define	gCONST		%0001
#define	gLINEAR		%0010
#define	gQUADRATIC		%0100

;Material
#define	gMATERIAL		true
#define	gSPECULAR		$0001
#define	gSHININESS		$0002

;VBO
#define	gVBO_MASK		$01
#define	gVBO_SET		$0100
#define	gVBO_DATA		$0200
#define	gVBO_FORMAT	$0400

;Query
#define	gSAMPLE_PASSED	%00000001
#define	gLAST_ERROR	%00000010

;Type
#define	gWVEC3		6
#define	gBVEC3		3
#define	gWVEC2		4
#define	gBVEC2		2
#define	gWORD			2
#define	gBYTE			1

;Implementation Limits
#define	gMAX_IN_VSH	$FFFF		;infinity in parameters
#define	gMAX_OUT_VSH	15		;vbo limits
#define	gMAX_IN_FSH	15		;
#define	gMAX_OUT_FSH	1		;only color is out
#define	gMAX_LIGHT		4
#define	gMAX_TEXTURE	4
#define	gMAX_VBO		8
#define	gMAX_VBO_SIZE	4098
#define	gMAX_VBO_VERTEX	256
#define	gMAX_OUT_VERTEX	8
#define	gMAX_IN_VERTEX	8
#define	gMAX_CLIP_POINT	8

;Errors
#define	gOUT_OF_MEMORY	$FF
#define	gSTACK_FULL	$DF
#define	gUNKNOWN		$CF

gMatrix 	   	   = saveSScreen
gStencilBuff  	   = saveSScreen + 15
gError	   	   = saveSScreen + 17
gTexture	   	   = saveSScreen + 18

;aligned table
gMulTable	   	   = saveSScreen + 20
gSin 		   	   = saveSScreen + 276

;camera;8 bytes
gCamera 	   	   = saveSScreen + 532
gAxisAngle	   	   = saveSScreen + 532
gAngXY 	   	   = saveSScreen + 532
gAngZ 	   	   = saveSScreen + 533
gCPosX	   	   = saveSScreen + 534
gCPosY 	   	   = saveSScreen + 536
gCPosZ 	   	   = saveSScreen + 538
	
;vbo
gVBOInStream  	   = saveSScreen + 540		;const
gVBOPoint 	   	   = saveSScreen + 542		;const
gVBOVertex	   	   = saveSScreen + 544		;const
gVBOName	   	   = saveSScreen + 546		;
gVBOID 	   	   = saveSScreen + 551		;

;drawing
gDrawCall		   =	saveSScreen + 552

;shader
gVertexCall   	   = 	saveSScreen + 554
gGeometryCall 	   = 	saveSScreen + 556
gFragmentCall 	   = 	saveSScreen + 558

;vertex array
gArrayOffset	   = saveSScreen + 560
gVertexStream	   = saveSScreen + 542
gtmpInStream   	   = saveSScreen + 562
gtmpOutStream      = saveSScreen + 564

; geometry and shader vars
gVerticesIn	   =	saveSScreen + 566
gVertexIndex	   =	saveSScreen + 568
gReadIndex		   =	saveSScreen + 570
gEdgePoint		   =	saveSScreen + 571
; two bytes here is always set to 128,128
gRasterTable	   =	saveSScreen + 574
; size = 8*2 (16)
gEmitVertex	   =	saveSScreen + 590
; size = 8*16 (128), indirected

gFreeBuff100	   =	saveSScreen + 592

;light, 4 light available
gLIGHT_POOL   	   = saveSScreen + 692
gLIGHT0 	   	   = saveSScreen + 692
gLIGHT1 	   	   = saveSScreen + 701
gLIGHT2 	   	   = saveSScreen + 710
gLIGHT3 	   	   = saveSScreen + 719

;texture
gTextName	   	   = saveSScreen + 728
gTextID	   	   = saveSScreen + 734
gTEXTURE_POOL 	   = saveSScreen + 735
gTEXT0	   	   = saveSScreen + 735
gTEXT1	   	   = saveSScreen + 737
gTEXT2	   	   = saveSScreen + 739
gTEXT3	   	   = saveSScreen + 741

;VBO
gVBO_POOL	   	   = saveSScreen + 743
;16 bytes
gFree6b	   	   = saveSScreen + 761


;OP1-6
#define	gPixel		$8478
#define	gColor		$8478
#define	gScreenX		$8479
#define	gScreenY		$847A

#define	gPosition		$847B
#define	gPositionX		$847B
#define	gPositionY		$847D
#define	gPositionZ		$847F

#define	gVertex		$8481
#define	gVertexX		$8481
#define	gVertexY		$8483
#define	gVertexZ		$8485

#define	gNormal		$8487
#define	gNormalX		$8487
#define	gNormalY		$8488
#define	gNormalZ		$8489

#define	gTexCoord		$848A
#define	gTexCoordS		$848A
#define	gTexCoordT		$848B

#define	gFirstVertex	$847B
#define	gFirstVertexX	$847B
#define	gFirstVertexY	$847D
#define	gFirstVertexZ	$847F

#define	gSecondVertex	$8481
#define	gSecondVertexX	$8481
#define	gSecondVertexY	$8483
#define	gSecondVertexZ	$8485

#define	gLineX0		$848C
#define	gLineY0		$848D
#define	gLineX1		$848E
#define	gLineY1		$848F

#define	gCode			$8490
#define	gCode1		$8490
#define	gCode2		$8491
#define	gCurrCode		$8492

#define	gVBOCount		$848C

#define	gX0			$8493
#define	gY0			$8495
#define	gX1			$8497
#define	gY1			$8499


#macro	gFetchRaster(reg)	
#if reg!=l
  ld	l, reg
	ld 	h, gRasterCache/256
	ld	a, (hl)
	inc	h
	ld	l, (hl)
	ld	h, a
	ld	(gRasterCoord), hl	
#elseif
	ld 	h, gRasterCache/256
	ld	a, (hl)
	inc	h
	ld	l, (hl)
	ld	h, a
	ld	(gRasterCoord), hl
#endif
#endmacro

#endif
