
//**********************************************************************************************************************************************//
//Main Function - EL04_01: TCP Server Connection Data
//**********************************************************************************************************************************************//

static TCPS_SRV *tcpssup = NULL;
static TCP_STREAM *tcpcsup = NULL;

void com_libsuper000(COM_LIBSUPER000 *io)
{
	//Variable Input
	//**************************************************************************//
	BIT in01 = 0;

	//Variable Output
	//**************************************************************************//
	FL ou01 = 0, ou09 = 0;
	ULI ou02 = 0;
	ULI ou03 = 0;
	UI ou04 = 0, ou05 = 0, ou06 = 0, ou07 = 0, ou08 = 0, ou10 = 0;


	//Variable Local
	//**************************************************************************//
	FL dataIn01 = 0;
	FL Group02;
	FL Adrid02;

	UI Count = 0;
	UI Count02 = 0;
	UI sort;

	//Settings
	//**************************************************************************//
	FL poort = 59886;
	FL bytesIn = 0;
	FL bytesOut = 0;




	//Read Input/Outputs
	//**************************************************************************//
	in01 = *io->Input01;
	ou01 = *io->Output01;
	ou02 = *io->Output02;
	ou03 = *io->Output03;
	ou04 = *io->Output04;
	ou05 = *io->Output05;
	ou06 = *io->Output06;
	ou07 = *io->Output07;
	ou08 = *io->Output08;
	ou09 = *io->Output09;
	ou10 = *io->Output10;


	//Set NULL
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0;
		*io->__s02 = 0;
		*io->__s03 = 0;
		*io->__s04 = 0;
		*io->__b01 = 0;
		*io->__b02 = 0;
		*io->__se01 = 0;
		*io->__se02 = 0;
		*io->__se03 = 0;

		UI Count03;
		for (Count03 = 0; Count03 < 100; Count03++)
		{
			*((io->__sa01) + Count03) = 0;
		}
		for (sort = 0; sort < 17; sort++)
		{
			*((io->__Discr) + sort) = 0;
		}
		for (sort = 0; sort < 34; sort++)
		{
			*((io->__Discr2) + sort) = 0;
		}
	}

	//Buffer
	//**************************************************************************//

	UC buf1[256];
	UC buf2[256];
	UC buf3[256];

	//Initialisation socket
	//**************************************************************************//
	if (in01 > 0 && tcpssup == 0)
	{

		tcpssup = TCPSSRV_CreateServer(poort);//TCPS_SRV*   TCPSSRV_CreateServer    (int iPort);
		ou01 = TCPSSRV_AcceptRequested(tcpssup);//aBOOL       TCPSSRV_AcceptRequested (TCPS_SRV* pTCPSSRV);
		ou02 = tcpssup;
		ou03 = tcpcsup;
		ou04 = 1;
		ou05 = 1;
		ou06 = 1;
		ou07 = 1;
		ou08 = 1;
		ou09 = 1;
		ou10 = 1;

	}
	else if (tcpssup != 0)
	{
		ou07 = 1;
		if (TCPSSRV_AcceptRequested(tcpssup))
		{

			*io->__s01 = 0;
			*io->__s02 = 0;
			*io->__s03 = 0;
			*io->__s04 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
			*io->__se01 = 0;
			*io->__se02 = 0;
			*io->__se03 = 0;

			ou07 = 2;
			tcpcsup = TCPSSRV_Accept(tcpssup, 10000);// TCP_STREAM* TCPSSRV_Accept(TCPS_SRV* pTCPSSRV, int iTimeoutMS);

			if (tcpcsup != 0)
			{
				ou07 = 3;
				if (TCPS_ConnectNblkComplete(tcpcsup) == 0)
				{
					ou07 = 4;
					if (TCPS_GetRemotePort(tcpcsup) != 0)
					{
						ou07 = 5;
						*io->__s01 = 5;

					}
				}
			}

		}
		//Send and Recieve Socket
		//********************************************************************************************************************************************************//
		if (*io->__s01 == 5)
		{
			ou08 = 0;
			*io->__s02 = sizeof(buf1);


			*io->__se01 = 0;
			*io->__se02 = 0;
			*io->__se03 = 0;
			//Casting
			//**************************************************************************//
			bytesIn = TCPS_ReceiveData(tcpcsup, buf2, sizeof(buf2) + 1, 1000);
			*io->__b01 += bytesIn;
			sscanf(buf2, "%f, %f, %f", &*io->__se01, &*io->__se02, &*io->__se03);

			*io->EXTGroupid = *io->__se01;
			*io->EXTAdrid = *io->__se02;
			*io->EXTFuncid = *io->__se03;

			FL EXTGroupid = *io->EXTGroupid;
			FL EXTAdrid = *io->EXTAdrid;
			FL EXTFuncid = *io->EXTFuncid;
			//Test
			//**************************************************************************//


			//Count Devices
			//**************************************************************************//
			INPUTDATA2_LIBSUPER000 **ppst;
			INPUTDATA2_LIBSUPER000 *pst;

			if (EXTGroupid != 0)
			{
				ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
				while ((pst = *ppst) != NULL)
				{
					if (
						(*pst->Groupid > 0)
						)
					{
						Count++;
					}
					ppst++;
				}
			}
			//Data Harvest
			//**************************************************************************//
			if (Count)
			{
				memset(buf1, 0, sizeof(buf1));
				memset(buf2, 0, sizeof(buf2));
				memset(buf3, 0, sizeof(buf3));

				for (sort = 0; sort < 100; sort++)
				{
					*((io->__sa01) + sort) = 0;
				}
				for (sort = 0; sort < 17; sort++)
				{
					*((io->__Discr) + sort) = 0;
				}
				for (sort = 0; sort < 34; sort++)
				{
					*((io->__Discr2) + sort) = 0;
				}
				Count02 = 0;
				UI ax = 0;
				UI uxe = 0;

				//Data Harvest
				//**************************************************************************//

				ppst = (INPUTDATA2_LIBSUPER000 **)inputdata2_libsuper000_ST;
				while ((pst = *ppst) != NULL)
				{
					//Group
					//**************************************************************************//
					if (EXTGroupid == 99)//if equals then needs to stop
					{
						//Last Change
						//**************************************************************************/		
						UI idx;
						UI *pquelle = pst->Discr;
						UI *pziel = io->Discr;

						for (idx = 0; idx < 17; idx++)
						{
							*((io->__Discr) + idx) = *pquelle;
							*pziel = *pquelle;
							pziel++;
							pquelle++;
						}

						Count02++;
						//Load data in arry
						//**************************************************************************//
						Group02 = *pst->Groupid;
						ax = 0;
						uxe = 0;
						*((io->__sa01) + Count02) = Group02;
						for (uxe = 0; uxe < Count02; uxe++)
						{
							(*((io->__sa01) + uxe) == (*((io->__sa01) + Count02))) ? (Count02 -= 1) : (ax = 2);
						}

						if (Count02 == 100)
						{
							Count02 = 0;
						}
						//Output Text
						//**************************************************************************//
					}
					if (
						(*pst->Groupid == EXTGroupid) &&
						(EXTAdrid == 0)
						)
					{
						//Last Change
						//**************************************************************************/		
						UI idx;
						UI *pquelle = pst->Discr;
						UI *pziel = io->Discr;

						for (idx = 0; idx < 17; idx++)
						{
							*((io->__Discr) + idx) = *pquelle;
							*pziel = *pquelle;
							pziel++;
							pquelle++;

						}



						Count02++;
						//Load data in arry
						//**************************************************************************//
						Adrid02 = *pst->Adrid;
						ax = 0;
						uxe = 0;
						*((io->__sa01) + Count02) = Adrid02;
						for (uxe = 0; uxe < Count02; uxe++)
						{
							(*((io->__sa01) + uxe) == (*((io->__sa01) + Count02))) ? (Count02 -= 1) : (ax = 2);
						}
						if (Count02 == 100)
						{
							Count02 = 0;
						}
					}
					if (
						(*pst->Groupid == EXTGroupid) &&
						(*pst->Adrid == EXTAdrid) &&
						(*pst->Funcid == EXTFuncid)
						)
					{
						//Last Change
						//**************************************************************************//
						UI idx;
						UI *pquelle = pst->Discr;
						UI *pziel = io->Discr;

						for (idx = 0; idx < 17; idx++)
						{
							*((io->__Discr) + idx) = *pquelle;
							*pziel = *pquelle;
							pziel++;
							pquelle++;

						}

						//Load data in arry
						//**************************************************************************//
						*((io->__sa01) + 1) = *pst->Input01;
						*((io->__sa01) + 2) = *pst->Input02;
						*((io->__sa01) + 3) = *pst->Input03;
						*((io->__sa01) + 4) = *pst->Input04;
						*((io->__sa01) + 5) = *pst->Input05;
						*((io->__sa01) + 6) = *pst->Input06;
						*((io->__sa01) + 7) = *pst->Input07;
						*((io->__sa01) + 8) = *pst->Input08;
						*((io->__sa01) + 9) = *pst->Input09;
						*((io->__sa01) + 10) = *pst->Input10;
						*((io->__sa01) + 11) = *pst->Input11;
						*((io->__sa01) + 12) = *pst->Input12;
						*((io->__sa01) + 13) = *pst->Input13;
						*((io->__sa01) + 14) = *pst->Input14;
						*((io->__sa01) + 15) = *pst->Input15;
						*((io->__sa01) + 16) = *pst->Input16;
						*((io->__sa01) + 17) = *pst->Input17;
						*((io->__sa01) + 18) = *pst->Input18;
						*((io->__sa01) + 19) = *pst->Input19;
						*((io->__sa01) + 20) = *pst->Input20;
						Count02 = 20;
					}
					else if (
						(*pst->Groupid != EXTGroupid) ||
						(*pst->Adrid != EXTAdrid) ||
						(*pst->Funcid != EXTFuncid)
						)//if equals then needs to stop
					{
						//Output Text
						//**************************************************************************//
						//UI idx;
						//UI *pquelle = pst->Discr;
						//UI *pziel = io->Discr;

						//for (idx = 0; idx < 17; idx++)
						//{
						//	*((io->__Discr) + idx) = *pquelle;
						//	*pziel = *pquelle;
						//	pziel++;
						//	pquelle++;

						//}
					}
					ppst++;
				}
				//Data laden
				//**************************************************************************//
				UC *pos = buf1;
				memset(pos, 0, sizeof(buf1));
				UI idx2;
				UI idx3;

				UI j = 0;
				UI i = 0;


				for (i = 0; i < 17; i++)
				{

					if (*((io->__Discr) + i) > 0xff)
					{
						UC secondchar = *((io->__Discr) + i);
						*((io->__Discr2) + j) = secondchar;
						j++;
						UC firstchar = *((io->__Discr) + i) >> 8;
						*((io->__Discr2) + j) = firstchar;
						j++;
					}
					else
					{
						*((io->__Discr2) + j) = *((io->__Discr) + i);
						j++;
					}
				}
				pos += sprintf(pos, "start");
				pos += sprintf(pos, ", ");
				pos += sprintf(pos, "%.i", sizeof(buf1));
				pos += sprintf(pos, ", ");
				for (idx2 = 0; idx2 < 16; idx2++)
				{
					pos += sprintf(pos, "%c", *((io->__Discr2) + idx2));
				}
				pos += sprintf(pos, ", ");
				for (idx3 = 1; idx3 < 21; idx3++)
				{
					pos += sprintf(pos, "%.2f", *((io->__sa01) + idx3));
					pos += sprintf(pos, ", ");
				}
				pos += sprintf(pos, ", finish");
			
				ou08 = 1;
			}	
			else
			{
				sprintf(buf1, "%.2f", "%.2f", "%.2f", 0, 0, 0);
				ou08 = 2;
				//Output Text
					//**************************************************************************//
				UI *pziel = io->Discr;
				*pziel = 0x6148;
				pziel++;
				*pziel = 0x6C6C;
				pziel++;
				*pziel = 0x206F;
				pziel++;
				*pziel = 0;
			}
			//Test
			//**************************************************************************//
			*io->__s02 = sizeof(buf1) + 1;

			if (bytesIn > 0)
			{
				
				*io->__s04 = dataIn01;
				while (*io->__s02 > 0)
				{
					bytesOut = TCPS_SendData(tcpcsup, buf1, sizeof(buf1) + 1);
					*io->__s03 = bytesOut;
					ou08 = 2;
					*io->__b02 += bytesOut;
					*io->__s02 -= *io->__s03;
				}

			}
		}
		else
		{
			*io->__s01 = 0;
			*io->__s02 = 0;
			*io->__s03 = 0;
			*io->__s04 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
			*io->__se01 = 0;
			*io->__se02 = 0;
			*io->__se03 = 0;
			for (sort = 0; sort < 100; sort++)
			{
				*((io->__sa01) + sort) = 0;
			}
			for (sort = 0; sort < 17; sort++)
			{
				*((io->__Discr) + sort) = 0;
			}
			for (sort = 0; sort < 34; sort++)
			{
				*((io->__Discr2) + sort) = 0;
			}
		}
		//Disconect and Close Socket
		//**************************************************************************//
		if (in01 == 0)
		{
			TCPSSRV_RemoveServer(&tcpssup);
			TCPS_Disconnect(&tcpcsup);
			*io->__s01 = 0;
			*io->__s02 = 0;
			*io->__s03 = 0;
			*io->__s04 = 0;
			*io->__b01 = 0;
			*io->__b02 = 0;
			*io->__se01 = 0;
			*io->__se02 = 0;
			*io->__se03 = 0;
			for (sort = 0; sort < 100; sort++)
			{
				*((io->__sa01) + sort) = 0;
			}
			for (sort = 0; sort < 17; sort++)
			{
				*((io->__Discr) + sort) = 0;
			}
			for (sort = 0; sort < 34; sort++)
			{
				*((io->__Discr2) + sort) = 0;
			}
		}
		//Set Outputs
		//**************************************************************************//
		ou01 = TCPSSRV_AcceptRequested(tcpssup);
		ou02 = tcpssup;
		ou03 = tcpcsup;
		ou04 = *io->__s02;
		ou05 = *io->__b01;
		ou06 = *io->__b02;
		ou09 = *io->__s04;
		ou10 = bytesOut;
	}
	else if (in01 == 0)
	{
		TCPSSRV_RemoveServer(&tcpssup);//void        TCPSSRV_RemoveServer    (TCPS_SRV** ppTCPSSRV);
		TCPS_Disconnect(&tcpcsup);
		ou01 = TCPSSRV_AcceptRequested(tcpssup);
		ou02 = tcpssup;
		ou03 = tcpcsup;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 0;
		ou09 = 0;
		ou10 = 0;
	}
	else
	{
		ou01 = TCPSSRV_AcceptRequested(tcpssup);
		ou02 = tcpssup;
		ou03 = tcpcsup;
		ou04 = 0;
		ou05 = 0;
		ou06 = 0;
		ou07 = 0;
		ou08 = 9884;
		ou09 = 9884;
		ou10 = 9884;
	}

	//Write Output
	//**************************************************************************//
	*io->Output01 = ou01;
	*io->Output02 = ou02;
	*io->Output03 = ou03;
	*io->Output04 = ou04;
	*io->Output05 = ou05;
	*io->Output06 = ou06;
	*io->Output07 = ou07;
	*io->Output08 = ou08;
	*io->Output09 = ou09;
	*io->Output10 = ou10;
}










