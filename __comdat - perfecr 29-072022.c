
//**********************************************************************************************************************************************//
//Main Function - EL04_01: TCP Server Connection Data lean
//**********************************************************************************************************************************************//


static TCPS_SRV *tcpsdat = NULL;
static TCP_STREAM *tcpcdat = NULL;


void com4_libsuper000(COM4_LIBSUPER000 *io)
{

//Variable Input
	//**************************************************************************//
	BIT in01 = 0;


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
FL poort = 59889;
FL bytesIn = 0;
FL bytesOut = 0;

//Read Input/Outputs
//**************************************************************************//
in01 = *io->Input01;


//Set NULL
//**************************************************************************//
if (PLUGIN_GetStartFlag())
{
	*io->__s01 = 0;
	*io->__s02 = 0;
	*io->__s03 = 0;
	*io->__s04 = 0;
	*io->__s05 = 0;

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

UC buf1[255];
UC buf2[255];
UC buf3[255];

//Initialisation socket
//**************************************************************************//
if (in01 > 0 && tcpsdat == 0)
{

	tcpsdat = TCPSSRV_CreateServer(poort);//TCPS_SRV*   TCPSSRV_CreateServer    (int iPort);

}
else if (tcpsdat != 0)
{
	if (TCPSSRV_AcceptRequested(tcpsdat))
	{

		*io->__s01 = 0;
		*io->__s02 = 0;
		*io->__s03 = 0;
		*io->__s04 = 0;


		tcpcdat = TCPSSRV_Accept(tcpsdat, 10000);// TCP_STREAM* TCPSSRV_Accept(TCPS_SRV* pTCPSSRV, int iTimeoutMS);

		if (tcpcdat != 0)
		{
			if (TCPS_ConnectNblkComplete(tcpcdat) == 0)
			{
				if (TCPS_GetRemotePort(tcpcdat) != 0)
				{
					*io->__s01 = 5;
				}
			}
		}

	}
	//Send and Recieve Socket
	//********************************************************************************************************************************************************//
	if (*io->__s01 == 5)
	{
		*io->__s02 = sizeof(buf1) + 1;
		bytesIn = TCPS_ReceiveData(tcpcdat, buf3, sizeof(buf3) + 1, 1000);



		//Count Devices
		//**************************************************************************//
		INPUTDATA2_LIBSUPER000 **ppst;
		INPUTDATA2_LIBSUPER000 *pst;

		if (*io->__s01 == 5)
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
		*io->__s01 == 0;

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
				if (
					(*pst->Funcid == 3 && *io->__s02 != 99)
					)
				{
					*io->__s02 = 99;

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



					//Load data in arry
					//**************************************************************************//
					if (Count02 == 0)
					{
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
					else
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
					}
					if (Count02 == 20)
					{
						//Data laden
						//**************************************************************************//
						Group02 = *pst->Groupid;
						Adrid02 = *pst->Adrid;

						//Name
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

						//Name 
						//**************************************************************************//
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
						//message build
						UC *pos = buf1;
						memset(pos, 0, sizeof(buf1));
						UI idx2;
						UI idx3;

						pos += sprintf(pos, "start");
						pos += sprintf(pos, ", ");
						pos += sprintf(pos, "%.i", sizeof(buf1));
						pos += sprintf(pos, ", ");
						pos += sprintf(pos, "%.f", Group02);
						pos += sprintf(pos, ", ");
						pos += sprintf(pos, "%.f", Adrid02);
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
						pos += sprintf(pos, ", ");

						*io->__s02 = sizeof(buf1) + 1;

						if (bytesIn > 0)
						{
							while (*io->__s02 > 0)
							{
								bytesOut = TCPS_SendData(tcpcdat, buf1, sizeof(buf1) + 1);
								*io->__s03 = bytesOut;
								*io->__s02 -= *io->__s03;
							}
						}
						//end message build

					}
					else
					{
						TCPSSRV_RemoveServer(&tcpsdat);
						TCPS_Disconnect(&tcpcdat);
						memset(buf1, 0, sizeof(buf1));
						memset(buf2, 0, sizeof(buf2));
						memset(buf3, 0, sizeof(buf3));

						*io->__s01 = 0;
						*io->__s02 = 0;
						*io->__s03 = 0;
						*io->__s04 = 0;
						for (sort = 0; sort < 10000; sort++)
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
				}
				ppst++;

			}

			TCPSSRV_RemoveServer(&tcpsdat);
			TCPS_Disconnect(&tcpcdat);
			memset(buf1, 0, sizeof(buf1));
			memset(buf2, 0, sizeof(buf2));
			memset(buf3, 0, sizeof(buf3));

			*io->__s01 = 0;
			*io->__s02 = 0;
			*io->__s03 = 0;
			*io->__s04 = 0;
			for (sort = 0; sort < 10000; sort++)
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
		else
		{
			TCPSSRV_RemoveServer(&tcpsdat);
			TCPS_Disconnect(&tcpcdat);
			memset(buf1, 0, sizeof(buf1));
			memset(buf2, 0, sizeof(buf2));
			memset(buf3, 0, sizeof(buf3));

			*io->__s01 = 0;
			*io->__s02 = 0;
			*io->__s03 = 0;
			*io->__s04 = 0;
			for (sort = 0; sort < 10000; sort++)
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
	}
	else
	{
		*io->__s01 = 0;
		*io->__s02 = 0;
		*io->__s03 = 0;
		*io->__s04 = 0;

		for (sort = 0; sort < 10000; sort++)
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
		TCPSSRV_RemoveServer(&tcpsdat);
		TCPS_Disconnect(&tcpcdat);
		*io->__s01 = 0;
		*io->__s02 = 0;
		*io->__s03 = 0;
		*io->__s04 = 0;

		for (sort = 0; sort < 10000; sort++)
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
}
else
{
	TCPSSRV_RemoveServer(&tcpsdat);//void        TCPSSRV_RemoveServer    (TCPS_SRV** ppTCPSSRV);
	TCPS_Disconnect(&tcpcdat);
}


}