#include "variadef.h"
#include "__plugin.h"
#include "__super.h"
#include "__sock1.h"

#include "__comdatorg.c"
#include "__comerr.c"
#include "__commai.c"
#include "__comdat.c"
#include "__comwea.c"
#include "__comlis.c"



void input_libsuper000(INPUT_LIBSUPER000 *io) {
	//test//

	if (PLUGIN_GetStartFlag())
	{
		*io->__Change = 1;
		*io->__Input01 = *io->Input01;
	}

	UI Groupid = *io->Groupid;
	UI Adrid = *io->Adrid;
	UI Funcid = *io->Funcid;

	OUTPUT_LIBSUPER000 **ppst;
	OUTPUT_LIBSUPER000 *pst;

	UI Count = 0;

	if (*io->__Input01 != *io->Input01)
	{
		*io->__Change = 1;
	}

	*io->__Input01 = *io->Input01;



	ppst = (OUTPUT_LIBSUPER000 **)output_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Adrid == Adrid) &&
			(*pst->Funcid == Funcid)
			)
		{
			Count++;
		}

		ppst++;
	}

	if (!Count)
	{
		*io->Numbers = 0;
	}

 }

void output_libsuper000(OUTPUT_LIBSUPER000 *io) {
	//test//
	UI Groupid = *io->Groupid;
	UI Adrid = *io->Adrid;
	UI Funcid = *io->Funcid;

	INPUT_LIBSUPER000 **ppst;
	INPUT_LIBSUPER000 *pst;
	INPUT_LIBSUPER000 *pmin;

	UI Count = 0;
	FL Min;
	FL Max;
	FL Sum = 0.0;

	FL Input01;

	ppst = (INPUT_LIBSUPER000 **)input_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Adrid == Adrid) &&
			(*pst->Funcid == Funcid)
			)
		{
			Count++;

			Input01 = *pst->Input01;

			if (Count == 1)
			{
				Min = Input01;
				Max = Input01;
				Sum = Input01;
				pmin = pst;
			}
			else
			{
				Sum = Sum + Input01;

				if (Input01 < Min)
				{
					Min = Input01;
					pmin = pst;
				}
				if (Input01 > Max)
				{
					Max = Input01;
				}
			}


		}

		ppst++;
	}

	if (Count)
	{
		*io->Mittel = Sum / Count;
		*io->Min = Min;
		*io->Max = Max;

		UI idx;
		UI *pquelle = pmin->Discr;
		UI *pziel = io->Discr;
		for (idx = 0; idx < 17; idx++)
		{
			*pziel = *pquelle;
			pziel++;
			pquelle++;
		}

		ppst = (INPUT_LIBSUPER000 **)input_libsuper000_ST;
		while ((pst = *ppst) != NULL)
		{

			if (
				(*pst->Groupid == Groupid) &&
				(*pst->Adrid == Adrid) &&
				(*pst->Funcid == Funcid)
				)
			{
				*pst->Numbers = Count;
			}

			ppst++;

		}
	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}

	*io->Numbers = Count;

}

void inputdata2_libsuper000(INPUTDATA2_LIBSUPER000 *io) {


	//Variable Input
	//**************************************************************************//
	FL in01 = 0, in02 = 0, in03 = 0, in04 = 0, in05 = 0, in06 = 0, in07 = 0, in08 = 0, in09 = 0, in10 = 0,
		in11 = 0, in12 = 0, in13 = 0, in14 = 0, in15 = 0, in16 = 0, in17 = 0, in18 = 0, in19 = 0, in20 = 0;
	//Read Input & Output
	//**************************************************************************//
	in01 = *io->Input01, in02 = *io->Input02, in03 = *io->Input03, in04 = *io->Input04, in05 = *io->Input05, in06 = *io->Input06, in07 = *io->Input07, in08 = *io->Input08, in09 = *io->Input09, in10 = *io->Input10,
		in11 = *io->Input11, in12 = *io->Input12, in13 = *io->Input13, in14 = *io->Input14, in15 = *io->Input15, in16 = *io->Input16, in17 = *io->Input17, in18 = *io->Input18, in19 = *io->Input19, in20 = *io->Input20;


	if (PLUGIN_GetStartFlag())
	{
		*io->__Change = 1;
	}

	UI Groupid = *io->Groupid;
	UI Adrid = *io->Adrid;
	UI Funcid = *io->Funcid;

	OUTPUTDATA_LIBSUPER000 **ppst;
	OUTPUTDATA_LIBSUPER000 *pst;

	UI Count = 0;

	ppst = (OUTPUTDATA_LIBSUPER000 **)outputdata_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Adrid == Adrid) &&
			(*pst->Funcid == Funcid)
			)
		{
			Count++;
		}

		ppst++;
	}

	if (!Count)
	{
		*io->Numbers = 0;
	}

}

void outputdata_libsuper000(OUTPUTDATA_LIBSUPER000 *io) 
{

	//Variable Input
	//**************************************************************************//
	FL Input01 = 0, Input02 = 0, Input03 = 0, Input04 = 0, Input05 = 0, Input06 = 0, Input07 = 0, Input08 = 0, Input09 = 0, Input10 = 0,
		Input11 = 0, Input12 = 0, Input13 = 0, Input14 = 0, Input15 = 0, Input16 = 0, Input17 = 0, Input18 = 0, Input19 = 0, Input20 = 0;
	

	UI Groupid = *io->Groupid;
	UI Adrid = *io->Adrid;
	UI Funcid = *io->Funcid;

	INPUTDATA2_LIBSUPER000 **ppst;
	INPUTDATA2_LIBSUPER000 *pst;
	INPUTDATA2_LIBSUPER000 *pmin;
	UI Count = 0;

	ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Adrid == Adrid) &&
			(*pst->Funcid == Funcid)
			)
		{
			Count++;
			pmin = pst;
		}

		ppst++;
	}
	if (Count)
	{
		UI idx;
		UI *pquelle = pmin->Discr;
		UI *pziel = io->Discr;
		for (idx = 0; idx < 17; idx++)
		{
			*pziel = *pquelle;
			pziel++;
			pquelle++;
		}


		ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
		while ((pst = *ppst) != NULL)
		{

			if (
				(*pst->Groupid == Groupid) &&
				(*pst->Adrid == Adrid) &&
				(*pst->Funcid == Funcid)
				)
			{
				*pst->Numbers = Count;
				Input01 = *pst->Input01;
				Input02 = *pst->Input02;
				Input03 = *pst->Input03;
				Input04 = *pst->Input04;
				Input05 = *pst->Input05;
				Input06 = *pst->Input06;
				Input07 = *pst->Input07;
				Input08 = *pst->Input08;
				Input09 = *pst->Input09;
				Input10 = *pst->Input10;
				Input11 = *pst->Input11;
				Input12 = *pst->Input12;
				Input13 = *pst->Input13;
				Input14 = *pst->Input14;
				Input15 = *pst->Input15;
				Input16 = *pst->Input16;
				Input17 = *pst->Input17;
				Input18 = *pst->Input18;
				Input19 = *pst->Input19;
				Input20 = *pst->Input20;
			}

			ppst++;
		}
	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}

	*io->Output01 = Input01, *io->Output02 = Input02, *io->Output03 = Input03, *io->Output04 = Input04, *io->Output05 = Input05, *io->Output06 = Input06, *io->Output07 = Input07, *io->Output08 = Input08, *io->Output09 = Input09, *io->Output10 = Input10,
		*io->Output11 = Input11, *io->Output12 = Input12, *io->Output13 = Input13, *io->Output14 = Input14, *io->Output15 = Input15, *io->Output16 = Input16, *io->Output17 = Input17, *io->Output18 = Input18, *io->Output19 = Input19, *io->Output20 = Input20;
	*io->Numbers = Count;
}

void outputdatasum_libsuper000(OUTPUTDATASUM_LIBSUPER000 *io)
{

	//Variable Input
	//**************************************************************************//
	UI Groupid = *io->Groupid;
	UI Funcid = *io->Funcid;

	INPUTDATA2_LIBSUPER000 **ppst;
	INPUTDATA2_LIBSUPER000 *pst;
	INPUTDATA2_LIBSUPER000 *pmin;

	UI Count = 0;
	FL Sum1 = 0.0, Sum2 = 0.0, Sum3 = 0.0, Sum4 = 0.0, Sum5 = 0.0, Sum6 = 0.0, Sum7 = 0.0, Sum8 = 0.0, Sum9 = 0.0, Sum10 = 0.0,
		Sum11 = 0.0, Sum12 = 0.0, Sum13 = 0.0, Sum14 = 0.0, Sum15 = 0.0, Sum16 = 0.0, Sum17 = 0.0, Sum18 = 0.0, Sum19 = 0.0, Sum20 = 0.0;

	FL Input01 = 0, Input02 = 0, Input03 = 0, Input04 = 0, Input05 = 0, Input06 = 0, Input07 = 0, Input08 = 0, Input09 = 0, Input10 = 0,
		Input11 = 0, Input12 = 0, Input13 = 0, Input14 = 0, Input15 = 0, Input16 = 0, Input17 = 0, Input18 = 0, Input19 = 0, Input20 = 0;


	ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Funcid == Funcid)
			)
		{
			Count++;
			pmin = pst;
			Input01 = *pst->Input01, Input02 = *pst->Input02, Input03 = *pst->Input03, Input04 = *pst->Input04, Input05 = *pst->Input05, Input06 = *pst->Input06, Input07 = *pst->Input07, Input08 = *pst->Input08, Input09 = *pst->Input09, Input10 = *pst->Input10,
				Input11 = *pst->Input11, Input12 = *pst->Input12, Input13 = *pst->Input13, Input14 = *pst->Input14, Input15 = *pst->Input15, Input16 = *pst->Input16, Input17 = *pst->Input17, Input18 = *pst->Input18, Input19 = *pst->Input19, Input20 = *pst->Input20;
			
			if (Count == 1)
			{
				Sum1 = Input01;
				Sum2 = Input02;
				Sum3 = Input03;
				Sum4 = Input04;
				Sum5 = Input05;
				Sum6 = Input06;
				Sum7 = Input07;
				Sum8 = Input08;
				Sum9 = Input09;
				Sum10 = Input10;
				Sum11 = Input11;
				Sum12 = Input12;
				Sum13 = Input13;
				Sum14 = Input14;
				Sum15 = Input15;
				Sum16 = Input16;
				Sum17 = Input17;
				Sum18 = Input18;
				Sum19 = Input19;
				Sum20 = Input20;
			}
			else
			{
				Sum1 = Sum1 + Input01;
				Sum2 = Sum2 + Input02;
				Sum3 = Sum3 + Input03;
				Sum4 = Sum4 + Input04;
				Sum5 = Sum5 + Input05;
				Sum6 = Sum6 + Input06;
				Sum7 = Sum7 + Input07;
				Sum8 = Sum8 + Input08;
				Sum9 = Sum9 + Input09;
				Sum10 = Sum10 + Input10;
				Sum11 = Sum11 + Input11;
				Sum12 = Sum12 + Input12;
				Sum13 = Sum13 + Input13;
				Sum14 = Sum14 + Input14;
				Sum15 = Sum15 + Input15;
				Sum16 = Sum16 + Input16;
				Sum17 = Sum17 + Input17;
				Sum18 = Sum18 + Input18;
				Sum19 = Sum19 + Input19;
				Sum20 = Sum20 + Input20;
			}
		}

		ppst++;
	}

	if (Count)
	{
		UI idx;
		UI *pquelle = pmin->Discr;
		UI *pziel = io->Discr;

		for (idx = 0; idx < 17; idx++)
		{
			*pziel = *pquelle;
			pziel++;
			pquelle++;
		}
			(Sum1 == 0) ? (*io->Output01 = 0) : (*io->Output01 = Sum1);
			(Sum2 == 0) ? (*io->Output02 = 0) : (*io->Output02 = Sum2);
			(Sum3 == 0) ? (*io->Output03 = 0) : (*io->Output03 = Sum3);
			(Sum4 == 0) ? (*io->Output04 = 0) : (*io->Output04 = Sum4);
			(Sum5 == 0) ? (*io->Output05 = 0) : (*io->Output05 = Sum5);
			(Sum6 == 0) ? (*io->Output06 = 0) : (*io->Output06 = Sum6);
			(Sum7 == 0) ? (*io->Output07 = 0) : (*io->Output07 = Sum7);
			(Sum8 == 0) ? (*io->Output08 = 0) : (*io->Output08 = Sum8);
			(Sum9 == 0) ? (*io->Output09 = 0) : (*io->Output09 = Sum9);
			(Sum10 == 0) ? (*io->Output10 = 0) : (*io->Output10 = Sum10);
			(Sum11 == 0) ? (*io->Output11 = 0) : (*io->Output11 = Sum11);
			(Sum12 == 0) ? (*io->Output12 = 0) : (*io->Output12 = Sum12);
			(Sum13 == 0) ? (*io->Output13 = 0) : (*io->Output13 = Sum13);
			(Sum14 == 0) ? (*io->Output14 = 0) : (*io->Output14 = Sum14);
			(Sum15 == 0) ? (*io->Output15 = 0) : (*io->Output15 = Sum15);
			(Sum16 == 0) ? (*io->Output16 = 0) : (*io->Output16 = Sum16);
			(Sum17 == 0) ? (*io->Output17 = 0) : (*io->Output17 = Sum17);
			(Sum18 == 0) ? (*io->Output18 = 0) : (*io->Output18 = Sum18);
			(Sum19 == 0) ? (*io->Output19 = 0) : (*io->Output19 = Sum19);
			(Sum20 == 0) ? (*io->Output20 = 0) : (*io->Output20 = Sum20);

	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}

	*io->Numbers = Count;
}
void outputdatamax_libsuper000(OUTPUTDATAMAX_LIBSUPER000 *io)
{

	//Variable Input
	//**************************************************************************//
	UI Groupid = *io->Groupid;
	UI Funcid = *io->Funcid;

	INPUTDATA2_LIBSUPER000 **ppst;
	INPUTDATA2_LIBSUPER000 *pst;
	INPUTDATA2_LIBSUPER000 *pmin;

	UI Count = 0;
	FL Sum1 = 0.0, Sum2 = 0.0, Sum3 = 0.0, Sum4 = 0.0, Sum5 = 0.0, Sum6 = 0.0, Sum7 = 0.0, Sum8 = 0.0, Sum9 = 0.0, Sum10 = 0.0,
		Sum11 = 0.0, Sum12 = 0.0, Sum13 = 0.0, Sum14 = 0.0, Sum15 = 0.0, Sum16 = 0.0, Sum17 = 0.0, Sum18 = 0.0, Sum19 = 0.0, Sum20 = 0.0;

	FL Input01 = 0, Input02 = 0, Input03 = 0, Input04 = 0, Input05 = 0, Input06 = 0, Input07 = 0, Input08 = 0, Input09 = 0, Input10 = 0,
		Input11 = 0, Input12 = 0, Input13 = 0, Input14 = 0, Input15 = 0, Input16 = 0, Input17 = 0, Input18 = 0, Input19 = 0, Input20 = 0;

	UI ax = 0;

	ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Funcid == Funcid)
			)
		{

			Count++;
			pmin = pst;
			Input01 = *pst->Input01, Input02 = *pst->Input02, Input03 = *pst->Input03, Input04 = *pst->Input04, Input05 = *pst->Input05, Input06 = *pst->Input06, Input07 = *pst->Input07, Input08 = *pst->Input08, Input09 = *pst->Input09, Input10 = *pst->Input10,
				Input11 = *pst->Input11, Input12 = *pst->Input12, Input13 = *pst->Input13, Input14 = *pst->Input14, Input15 = *pst->Input15, Input16 = *pst->Input16, Input17 = *pst->Input17, Input18 = *pst->Input18, Input19 = *pst->Input19, Input20 = *pst->Input20;

			if (Count == 1)
			{
				Sum1 = Input01;
				Sum2 = Input02;
				Sum3 = Input03;
				Sum4 = Input04;
				Sum5 = Input05;
				Sum6 = Input06;
				Sum7 = Input07;
				Sum8 = Input08;
				Sum9 = Input09;
				Sum10 = Input10;
				Sum11 = Input11;
				Sum12 = Input12;
				Sum13 = Input13;
				Sum14 = Input14;
				Sum15 = Input15;
				Sum16 = Input16;
				Sum17 = Input17;
				Sum18 = Input18;
				Sum19 = Input19;
				Sum20 = Input20;
			}
			else
			{	
				(Input01 > Sum1) ? (Sum1 = Input01) : (ax = 2);
				(Input02 > Sum2) ? (Sum2 = Input02) : (ax = 2);
				(Input03 > Sum3) ? (Sum3 = Input03) : (ax = 2);
				(Input04 > Sum4) ? (Sum4 = Input04) : (ax = 2);
				(Input05 > Sum5) ? (Sum5 = Input05) : (ax = 2);
				(Input06 > Sum6) ? (Sum6 = Input06) : (ax = 2);
				(Input07 > Sum7) ? (Sum7 = Input07) : (ax = 2);
				(Input08 > Sum8) ? (Sum8 = Input08) : (ax = 2);
				(Input09 > Sum9) ? (Sum9 = Input09) : (ax = 2);
				(Input10 > Sum10) ? (Sum10 = Input10) : (ax = 2);
				(Input11 > Sum11) ? (Sum11 = Input11) : (ax = 2);
				(Input12 > Sum12) ? (Sum12 = Input12) : (ax = 2);
				(Input13 > Sum13) ? (Sum13 = Input13) : (ax = 2);
				(Input14 > Sum14) ? (Sum14 = Input14) : (ax = 2);
				(Input15 > Sum15) ? (Sum15 = Input15) : (ax = 2);
				(Input16 > Sum16) ? (Sum16 = Input16) : (ax = 2);
				(Input17 > Sum17) ? (Sum17 = Input17) : (ax = 2);
				(Input18 > Sum18) ? (Sum18 = Input18) : (ax = 2);
				(Input19 > Sum19) ? (Sum19 = Input19) : (ax = 2);
				(Input20 > Sum20) ? (Sum20 = Input20) : (ax = 2);
			}
		}

		ppst++;
	}

	if (Count)
	{
		UI idx;
		UI *pquelle = pmin->Discr;
		UI *pziel = io->Discr;

		for (idx = 0; idx < 17; idx++)
		{
			*pziel = *pquelle;
			pziel++;
			pquelle++;
		}

		(Sum1 == 0) ? (*io->Output01 = 0) : (*io->Output01 = Sum1);
		(Sum2 == 0) ? (*io->Output02 = 0) : (*io->Output02 = Sum2);
		(Sum3 == 0) ? (*io->Output03 = 0) : (*io->Output03 = Sum3);
		(Sum4 == 0) ? (*io->Output04 = 0) : (*io->Output04 = Sum4);
		(Sum5 == 0) ? (*io->Output05 = 0) : (*io->Output05 = Sum5);
		(Sum6 == 0) ? (*io->Output06 = 0) : (*io->Output06 = Sum6);
		(Sum7 == 0) ? (*io->Output07 = 0) : (*io->Output07 = Sum7);
		(Sum8 == 0) ? (*io->Output08 = 0) : (*io->Output08 = Sum8);
		(Sum9 == 0) ? (*io->Output09 = 0) : (*io->Output09 = Sum9);
		(Sum10 == 0) ? (*io->Output10 = 0) : (*io->Output10 = Sum10);
		(Sum11 == 0) ? (*io->Output11 = 0) : (*io->Output11 = Sum11);
		(Sum12 == 0) ? (*io->Output12 = 0) : (*io->Output12 = Sum12);
		(Sum13 == 0) ? (*io->Output13 = 0) : (*io->Output13 = Sum13);
		(Sum14 == 0) ? (*io->Output14 = 0) : (*io->Output14 = Sum14);
		(Sum15 == 0) ? (*io->Output15 = 0) : (*io->Output15 = Sum15);
		(Sum16 == 0) ? (*io->Output16 = 0) : (*io->Output16 = Sum16);
		(Sum17 == 0) ? (*io->Output17 = 0) : (*io->Output17 = Sum17);
		(Sum18 == 0) ? (*io->Output18 = 0) : (*io->Output18 = Sum18);
		(Sum19 == 0) ? (*io->Output19 = 0) : (*io->Output19 = Sum19);
		(Sum20 == 0) ? (*io->Output20 = 0) : (*io->Output20 = Sum20);
	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}

	*io->Numbers = Count;
}
void outputdatamin_libsuper000(OUTPUTDATAMIN_LIBSUPER000 *io)
{

	//Variable Input
	//**************************************************************************//
	UI Groupid = *io->Groupid;
	UI Funcid = *io->Funcid;

	INPUTDATA2_LIBSUPER000 **ppst;
	INPUTDATA2_LIBSUPER000 *pst;
	INPUTDATA2_LIBSUPER000 *pmin;

	UI Count = 0;
	FL Sum1 = 0.0, Sum2 = 0.0, Sum3 = 0.0, Sum4 = 0.0, Sum5 = 0.0, Sum6 = 0.0, Sum7 = 0.0, Sum8 = 0.0, Sum9 = 0.0, Sum10 = 0.0,
		Sum11 = 0.0, Sum12 = 0.0, Sum13 = 0.0, Sum14 = 0.0, Sum15 = 0.0, Sum16 = 0.0, Sum17 = 0.0, Sum18 = 0.0, Sum19 = 0.0, Sum20 = 0.0;

	FL Input01 = 0, Input02 = 0, Input03 = 0, Input04 = 0, Input05 = 0, Input06 = 0, Input07 = 0, Input08 = 0, Input09 = 0, Input10 = 0,
		Input11 = 0, Input12 = 0, Input13 = 0, Input14 = 0, Input15 = 0, Input16 = 0, Input17 = 0, Input18 = 0, Input19 = 0, Input20 = 0;

	UI ax = 0;

	ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Funcid == Funcid)
			)
		{

			Count++;
			pmin = pst;
			Input01 = *pst->Input01, Input02 = *pst->Input02, Input03 = *pst->Input03, Input04 = *pst->Input04, Input05 = *pst->Input05, Input06 = *pst->Input06, Input07 = *pst->Input07, Input08 = *pst->Input08, Input09 = *pst->Input09, Input10 = *pst->Input10,
				Input11 = *pst->Input11, Input12 = *pst->Input12, Input13 = *pst->Input13, Input14 = *pst->Input14, Input15 = *pst->Input15, Input16 = *pst->Input16, Input17 = *pst->Input17, Input18 = *pst->Input18, Input19 = *pst->Input19, Input20 = *pst->Input20;

			if (Count == 1)
			{
				Sum1 = Input01;
				Sum2 = Input02;
				Sum3 = Input03;
				Sum4 = Input04;
				Sum5 = Input05;
				Sum6 = Input06;
				Sum7 = Input07;
				Sum8 = Input08;
				Sum9 = Input09;
				Sum10 = Input10;
				Sum11 = Input11;
				Sum12 = Input12;
				Sum13 = Input13;
				Sum14 = Input14;
				Sum15 = Input15;
				Sum16 = Input16;
				Sum17 = Input17;
				Sum18 = Input18;
				Sum19 = Input19;
				Sum20 = Input20;
			}
			else
			{
				(Input01 < Sum1) ? (Sum1 = Input01) : (ax = 2);
				(Input02 < Sum2) ? (Sum2 = Input02) : (ax = 2);
				(Input03 < Sum3) ? (Sum3 = Input03) : (ax = 2);
				(Input04 < Sum4) ? (Sum4 = Input04) : (ax = 2);
				(Input05 < Sum5) ? (Sum5 = Input05) : (ax = 2);
				(Input06 < Sum6) ? (Sum6 = Input06) : (ax = 2);
				(Input07 < Sum7) ? (Sum7 = Input07) : (ax = 2);
				(Input08 < Sum8) ? (Sum8 = Input08) : (ax = 2);
				(Input09 < Sum9) ? (Sum9 = Input09) : (ax = 2);
				(Input10 < Sum10) ? (Sum10 = Input10) : (ax = 2);
				(Input11 < Sum11) ? (Sum11 = Input11) : (ax = 2);
				(Input12 < Sum12) ? (Sum12 = Input12) : (ax = 2);
				(Input13 < Sum13) ? (Sum13 = Input13) : (ax = 2);
				(Input14 < Sum14) ? (Sum14 = Input14) : (ax = 2);
				(Input15 < Sum15) ? (Sum15 = Input15) : (ax = 2);
				(Input16 < Sum16) ? (Sum16 = Input16) : (ax = 2);
				(Input17 < Sum17) ? (Sum17 = Input17) : (ax = 2);
				(Input18 < Sum18) ? (Sum18 = Input18) : (ax = 2);
				(Input19 < Sum19) ? (Sum19 = Input19) : (ax = 2);
				(Input20 < Sum20) ? (Sum20 = Input20) : (ax = 2);
			}
		}

		ppst++;
	}

	if (Count)
	{
		UI idx;
		UI *pquelle = pmin->Discr;
		UI *pziel = io->Discr;

		for (idx = 0; idx < 17; idx++)
		{
			*pziel = *pquelle;
			pziel++;
			pquelle++;
		}

		(Sum1 == 0) ? (*io->Output01 = 0) : (*io->Output01 = Sum1);
		(Sum2 == 0) ? (*io->Output02 = 0) : (*io->Output02 = Sum2);
		(Sum3 == 0) ? (*io->Output03 = 0) : (*io->Output03 = Sum3);
		(Sum4 == 0) ? (*io->Output04 = 0) : (*io->Output04 = Sum4);
		(Sum5 == 0) ? (*io->Output05 = 0) : (*io->Output05 = Sum5);
		(Sum6 == 0) ? (*io->Output06 = 0) : (*io->Output06 = Sum6);
		(Sum7 == 0) ? (*io->Output07 = 0) : (*io->Output07 = Sum7);
		(Sum8 == 0) ? (*io->Output08 = 0) : (*io->Output08 = Sum8);
		(Sum9 == 0) ? (*io->Output09 = 0) : (*io->Output09 = Sum9);
		(Sum10 == 0) ? (*io->Output10 = 0) : (*io->Output10 = Sum10);
		(Sum11 == 0) ? (*io->Output11 = 0) : (*io->Output11 = Sum11);
		(Sum12 == 0) ? (*io->Output12 = 0) : (*io->Output12 = Sum12);
		(Sum13 == 0) ? (*io->Output13 = 0) : (*io->Output13 = Sum13);
		(Sum14 == 0) ? (*io->Output14 = 0) : (*io->Output14 = Sum14);
		(Sum15 == 0) ? (*io->Output15 = 0) : (*io->Output15 = Sum15);
		(Sum16 == 0) ? (*io->Output16 = 0) : (*io->Output16 = Sum16);
		(Sum17 == 0) ? (*io->Output17 = 0) : (*io->Output17 = Sum17);
		(Sum18 == 0) ? (*io->Output18 = 0) : (*io->Output18 = Sum18);
		(Sum19 == 0) ? (*io->Output19 = 0) : (*io->Output19 = Sum19);
		(Sum20 == 0) ? (*io->Output20 = 0) : (*io->Output20 = Sum20);

	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}

	*io->Numbers = Count;
}
void outputdataavg_libsuper000(OUTPUTDATAAVG_LIBSUPER000 *io)
{

	//Variable Input
	//**************************************************************************//
	UI Groupid = *io->Groupid;
	UI Funcid = *io->Funcid;

	INPUTDATA2_LIBSUPER000 **ppst;
	INPUTDATA2_LIBSUPER000 *pst;
	INPUTDATA2_LIBSUPER000 *pmin;

	UI Count = 0;
	FL Sum1 = 0.0, Sum2 = 0.0, Sum3 = 0.0, Sum4 = 0.0, Sum5 = 0.0, Sum6 = 0.0, Sum7 = 0.0, Sum8 = 0.0, Sum9 = 0.0, Sum10 = 0.0,
		Sum11 = 0.0, Sum12 = 0.0, Sum13 = 0.0, Sum14 = 0.0, Sum15 = 0.0, Sum16 = 0.0, Sum17 = 0.0, Sum18 = 0.0, Sum19 = 0.0, Sum20 = 0.0;

	FL Input01 = 0, Input02 = 0, Input03 = 0, Input04 = 0, Input05 = 0, Input06 = 0, Input07 = 0, Input08 = 0, Input09 = 0, Input10 = 0,
		Input11 = 0, Input12 = 0, Input13 = 0, Input14 = 0, Input15 = 0, Input16 = 0, Input17 = 0, Input18 = 0, Input19 = 0, Input20 = 0;


	ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Funcid == Funcid)
			)
		{

			Count++;
			pmin = pst;
			Input01 = *pst->Input01, Input02 = *pst->Input02, Input03 = *pst->Input03, Input04 = *pst->Input04, Input05 = *pst->Input05, Input06 = *pst->Input06, Input07 = *pst->Input07, Input08 = *pst->Input08, Input09 = *pst->Input09, Input10 = *pst->Input10,
				Input11 = *pst->Input11, Input12 = *pst->Input12, Input13 = *pst->Input13, Input14 = *pst->Input14, Input15 = *pst->Input15, Input16 = *pst->Input16, Input17 = *pst->Input17, Input18 = *pst->Input18, Input19 = *pst->Input19, Input20 = *pst->Input20;

			if (Count == 1)
			{
				Sum1 = Input01;
				Sum2 = Input02;
				Sum3 = Input03;
				Sum4 = Input04;
				Sum5 = Input05;
				Sum6 = Input06;
				Sum7 = Input07;
				Sum8 = Input08;
				Sum9 = Input09;
				Sum10 = Input10;
				Sum11 = Input11;
				Sum12 = Input12;
				Sum13 = Input13;
				Sum14 = Input14;
				Sum15 = Input15;
				Sum16 = Input16;
				Sum17 = Input17;
				Sum18 = Input18;
				Sum19 = Input19;
				Sum20 = Input20;
			}
			else
			{
				Sum1 = Sum1 + Input01;
				Sum2 = Sum2 + Input02;
				Sum3 = Sum3 + Input03;
				Sum4 = Sum4 + Input04;
				Sum5 = Sum5 + Input05;
				Sum6 = Sum6 + Input06;
				Sum7 = Sum7 + Input07;
				Sum8 = Sum8 + Input08;
				Sum9 = Sum9 + Input09;
				Sum10 = Sum10 + Input10;
				Sum11 = Sum11 + Input11;
				Sum12 = Sum12 + Input12;
				Sum13 = Sum13 + Input13;
				Sum14 = Sum14 + Input14;
				Sum15 = Sum15 + Input15;
				Sum16 = Sum16 + Input16;
				Sum17 = Sum17 + Input17;
				Sum18 = Sum18 + Input18;
				Sum19 = Sum19 + Input19;
				Sum20 = Sum20 + Input20;

			}
		}

		ppst++;
	}

	if (Count)
	{
		UI idx;
		UI *pquelle = pmin->Discr;
		UI *pziel = io->Discr;

		for (idx = 0; idx < 17; idx++)
		{
			*pziel = *pquelle;
			pziel++;
			pquelle++;
		}


		(Sum1 == 0) ? (*io->Output01 = 0) : (*io->Output01 = Sum1 / Count);
		(Sum2 == 0) ? (*io->Output02 = 0) : (*io->Output02 = Sum2 / Count);
		(Sum3 == 0) ? (*io->Output03 = 0) : (*io->Output03 = Sum3 / Count);
		(Sum4 == 0) ? (*io->Output04 = 0) : (*io->Output04 = Sum4 / Count);
		(Sum5 == 0) ? (*io->Output05 = 0) : (*io->Output05 = Sum5 / Count);
		(Sum6 == 0) ? (*io->Output06 = 0) : (*io->Output06 = Sum6 / Count);
		(Sum7 == 0) ? (*io->Output07 = 0) : (*io->Output07 = Sum7 / Count);
		(Sum8 == 0) ? (*io->Output08 = 0) : (*io->Output08 = Sum8 / Count);
		(Sum9 == 0) ? (*io->Output09 = 0) : (*io->Output09 = Sum9 / Count);
		(Sum10 == 0) ? (*io->Output10 = 0) : (*io->Output10 = Sum10 / Count);
		(Sum11 == 0) ? (*io->Output11 = 0) : (*io->Output11 = Sum11 / Count);
		(Sum12 == 0) ? (*io->Output12 = 0) : (*io->Output12 = Sum12 / Count);
		(Sum13 == 0) ? (*io->Output13 = 0) : (*io->Output13 = Sum13 / Count);
		(Sum14 == 0) ? (*io->Output14 = 0) : (*io->Output14 = Sum14 / Count);
		(Sum15 == 0) ? (*io->Output15 = 0) : (*io->Output15 = Sum15 / Count);
		(Sum16 == 0) ? (*io->Output16 = 0) : (*io->Output16 = Sum16 / Count);
		(Sum17 == 0) ? (*io->Output17 = 0) : (*io->Output17 = Sum17 / Count);
		(Sum18 == 0) ? (*io->Output18 = 0) : (*io->Output18 = Sum18 / Count);
		(Sum19 == 0) ? (*io->Output19 = 0) : (*io->Output19 = Sum19 / Count);
		(Sum20 == 0) ? (*io->Output20 = 0) : (*io->Output20 = Sum20 / Count);


	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}

	*io->Numbers = Count;
}

void coord_libsuper000(COORD_LIBSUPER000 *io) {

	if (PLUGIN_GetStartFlag())
	{
		*io->Numbers = 0;
	}

	INPUT_LIBSUPER000 **ppst;
	INPUT_LIBSUPER000 *pst;

	ppst = (INPUT_LIBSUPER000 **)input_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (*pst->__Change)
		{
			*io->Numbers = *io->Numbers +1;
			*pst->__Change = 0;


			UI idx;
			UI *pquelle = pst->Discr;
			UI *pziel = io->Discr;
			for (idx = 0; idx < 17; idx++)
			{
				*pziel = *pquelle;
				pziel++;
				pquelle++;
			}

		}

		ppst++;

	}

}
void sort_libsuper000(SORT_LIBSUPER000 *io) {

	UI sort;

	if (PLUGIN_GetStartFlag())
	{
		*io->Numbers = 0;

		for (sort = 0; sort < 100; sort++)
		{
			*((io->__sa01) + sort) = 0;
		}
	}


	FL Adrid02;
	UI Count = 0;
	UI Count02 = 0;
	ULI x01 = 0;
	UI Groupid = *io->Groupid;
	UI Funcid = *io->Funcid;

	INPUTDATA2_LIBSUPER000 **ppst;
	INPUTDATA2_LIBSUPER000 *pst;

	ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Funcid == Funcid)
			)
		{
			Count++;
		}

		ppst++;
	}
	if (Count)

	{
		for (sort = 0; sort < 100; sort++)
		{
			*((io->__sa01) + sort) = 0;
		}
		Count02 = 0;

		ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
		while ((pst = *ppst) != NULL)
		{
		
			if (
				(*pst->Groupid == Groupid) &&
				(*pst->Funcid == Funcid)
				)
			{
				Count02++;
	

				UI idx;
				UI *pquelle = pst->Discr;
				UI *pziel = io->Discr;

				for (idx = 0; idx < 17; idx++)
				{
					*pziel = *pquelle;
					pziel++;
					pquelle++;
				}


				//Load data in arry
				//**************************************************************************//
				Adrid02 = *pst->Adrid;
				*((io->__sa01) + Count02) = Adrid02;

				if (Count02 == 100)
				{
					Count02 = 0;
				}

			}

			ppst++;

		}

		*io->Output01 = *((io->__sa01) + 1);
		*io->Output02 = *((io->__sa01) + 2);
		*io->Output03 = *((io->__sa01) + 3);
		*io->Output04 = *((io->__sa01) + 4);
		*io->Output05 = *((io->__sa01) + 5);
		*io->Output06 = *((io->__sa01) + 6);
		*io->Output07 = *((io->__sa01) + 7);
		*io->Output08 = *((io->__sa01) + 8);
		*io->Output09 = *((io->__sa01) + 9);
		*io->Output10 = *((io->__sa01) + 10);
		*io->Output11 = *((io->__sa01) + 11);
		*io->Output12 = *((io->__sa01) + 12);
		*io->Output13 = *((io->__sa01) + 13);
		*io->Output14 = *((io->__sa01) + 14);
		*io->Output15 = *((io->__sa01) + 15);
		*io->Output16 = *((io->__sa01) + 16);
		*io->Output17 = *((io->__sa01) + 17);
		*io->Output18 = *((io->__sa01) + 18);
		*io->Output19 = *((io->__sa01) + 19);
		*io->Output20 = *((io->__sa01) + 20);
		*io->Output21 = *((io->__sa01) + 21);
		*io->Output22 = *((io->__sa01) + 22);
		*io->Output23 = *((io->__sa01) + 23);
		*io->Output24 = *((io->__sa01) + 24);
		*io->Output25 = *((io->__sa01) + 25);
		*io->Output26 = *((io->__sa01) + 26);
		*io->Output27 = *((io->__sa01) + 27);
		*io->Output28 = *((io->__sa01) + 28);
		*io->Output29 = *((io->__sa01) + 29);
		*io->Output30 = *((io->__sa01) + 30);
		*io->Output31 = *((io->__sa01) + 31);
		*io->Output32 = *((io->__sa01) + 32);
	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}

	*io->Numbers = Count;
}

void testvol_libsuper000(TESTVOL_LIBSUPER000 *io)
{

	UI sort;

	if (PLUGIN_GetStartFlag())
	{
		*io->Numbers = 0;

		for (sort = 0; sort < 100; sort++)
		{
			*((io->__sa01) + sort) = 0;
		}
	}

	UI Count = 0;
	UI Count02 = 0;
	UI Groupid = *io->Groupid;
	UI Funcid = *io->Funcid;

	FL Supplydemand = 0;
	FL Supplyactual = 0;
	FL Returndemand = 0;
	FL Returnactual = 0;

	INPUTDATA2_LIBSUPER000 **ppst;
	INPUTDATA2_LIBSUPER000 *pst;


	ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
	while ((pst = *ppst) != NULL)
	{

		if (
			(*pst->Groupid == Groupid) &&
			(*pst->Funcid == Funcid)
			)
		{
			Count++;
		}

		ppst++;
	}

	*io->Numbers = Count;

	if (Count)

	{
		for (sort = 0; sort < 200; sort++)
		{
			*((io->__sa01) + sort) = 0;
		}

		ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;

		while ((pst = *ppst) != NULL)
		{

			if (
				(*pst->Groupid == Groupid) &&
				(*pst->Adrid <= 98) &&
				(*pst->Funcid == Funcid)
				)
			{

				UI idx;
				UI *pquelle = pst->Discr;
				UI *pziel = io->Discr;
				UI ax = 0;

				for (idx = 0; idx < 17; idx++)
				{
					*pziel = *pquelle;
					pziel++;
					pquelle++;

				}

				//Load data in arry
				//**************************************************************************//
				Supplydemand = *pst->Input14;
				Supplyactual = *pst->Input13;
				Returndemand = *pst->Input16;
				Returnactual = *pst->Input15;

				Count02++;
				*((io->__sa01) + Count02) = ((Supplyactual / Supplydemand) * 100);

				UI idx2;
				for (idx2 = 0; idx2 < 17; idx2++)
				{
					(Count02 == 1) ? (*((io->Discr01) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 3) ? (*((io->Discr02) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 5) ? (*((io->Discr03) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 7) ? (*((io->Discr04) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 9) ? (*((io->Discr05) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 11) ? (*((io->Discr06) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 13) ? (*((io->Discr07) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 15) ? (*((io->Discr08) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 17) ? (*((io->Discr09) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 19) ? (*((io->Discr10) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 21) ? (*((io->Discr11) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 23) ? (*((io->Discr12) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 25) ? (*((io->Discr13) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 27) ? (*((io->Discr14) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 29) ? (*((io->Discr15) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 31) ? (*((io->Discr16) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 33) ? (*((io->Discr17) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 35) ? (*((io->Discr18) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 37) ? (*((io->Discr19) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 39) ? (*((io->Discr20) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 41) ? (*((io->Discr21) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 43) ? (*((io->Discr22) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 45) ? (*((io->Discr23) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 47) ? (*((io->Discr24) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 49) ? (*((io->Discr25) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 51) ? (*((io->Discr26) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 53) ? (*((io->Discr27) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 55) ? (*((io->Discr28) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 57) ? (*((io->Discr29) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 59) ? (*((io->Discr30) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 61) ? (*((io->Discr31) + idx2) = *((io->Discr) + idx2)) : (ax = 02);
					(Count02 == 63) ? (*((io->Discr32) + idx2) = *((io->Discr) + idx2)) : (ax = 02);

				}
				Count02++;
				*((io->__sa01) + Count02) = ((Returnactual / Returndemand) * 100);



				if (Count02 == 98)
				{
					Count02 = 0;
				}

			}
			ppst++;
		}

		*io->Output01 = *((io->__sa01) + 1);
		*io->Output02 = *((io->__sa01) + 2);
		*io->Output03 = *((io->__sa01) + 3);
		*io->Output04 = *((io->__sa01) + 4);
		*io->Output05 = *((io->__sa01) + 5);
		*io->Output06 = *((io->__sa01) + 6);
		*io->Output07 = *((io->__sa01) + 7);
		*io->Output08 = *((io->__sa01) + 8);
		*io->Output09 = *((io->__sa01) + 9);
		*io->Output10 = *((io->__sa01) + 10);
		*io->Output11 = *((io->__sa01) + 11);
		*io->Output12 = *((io->__sa01) + 12);
		*io->Output13 = *((io->__sa01) + 13);
		*io->Output14 = *((io->__sa01) + 14);
		*io->Output15 = *((io->__sa01) + 15);
		*io->Output16 = *((io->__sa01) + 16);
		*io->Output17 = *((io->__sa01) + 17);
		*io->Output18 = *((io->__sa01) + 18);
		*io->Output19 = *((io->__sa01) + 19);
		*io->Output20 = *((io->__sa01) + 20);
		*io->Output21 = *((io->__sa01) + 21);
		*io->Output22 = *((io->__sa01) + 22);
		*io->Output23 = *((io->__sa01) + 23);
		*io->Output24 = *((io->__sa01) + 24);
		*io->Output25 = *((io->__sa01) + 25);
		*io->Output26 = *((io->__sa01) + 26);
		*io->Output27 = *((io->__sa01) + 27);
		*io->Output28 = *((io->__sa01) + 28);
		*io->Output29 = *((io->__sa01) + 29);
		*io->Output30 = *((io->__sa01) + 30);
		*io->Output31 = *((io->__sa01) + 31);
		*io->Output32 = *((io->__sa01) + 32);
		*io->Output33 = *((io->__sa01) + 33);
		*io->Output34 = *((io->__sa01) + 34);
		*io->Output35 = *((io->__sa01) + 35);
		*io->Output36 = *((io->__sa01) + 36);
		*io->Output37 = *((io->__sa01) + 37);
		*io->Output38 = *((io->__sa01) + 38);
		*io->Output39 = *((io->__sa01) + 39);
		*io->Output40 = *((io->__sa01) + 40);
		*io->Output41 = *((io->__sa01) + 41);
		*io->Output42 = *((io->__sa01) + 42);
		*io->Output43 = *((io->__sa01) + 43);
		*io->Output44 = *((io->__sa01) + 44);
		*io->Output45 = *((io->__sa01) + 45);
		*io->Output46 = *((io->__sa01) + 46);
		*io->Output47 = *((io->__sa01) + 47);
		*io->Output48 = *((io->__sa01) + 48);
		*io->Output49 = *((io->__sa01) + 49);
		*io->Output50 = *((io->__sa01) + 50);
		*io->Output51 = *((io->__sa01) + 51);
		*io->Output52 = *((io->__sa01) + 52);
		*io->Output53 = *((io->__sa01) + 53);
		*io->Output54 = *((io->__sa01) + 54);
		*io->Output55 = *((io->__sa01) + 55);
		*io->Output56 = *((io->__sa01) + 56);
		*io->Output57 = *((io->__sa01) + 57);
		*io->Output58 = *((io->__sa01) + 58);
		*io->Output59 = *((io->__sa01) + 59);
		*io->Output60 = *((io->__sa01) + 60);
		*io->Output61 = *((io->__sa01) + 61);
		*io->Output62 = *((io->__sa01) + 62);
		*io->Output63 = *((io->__sa01) + 63);
		*io->Output64 = *((io->__sa01) + 64);
	}
	else
	{
		UI *pziel = io->Discr;
		*pziel = 0x6148;
		pziel++;
		*pziel = 0x6C6C;
		pziel++;
		*pziel = 0x206F;
		pziel++;
		*pziel = 0;
	}
}


