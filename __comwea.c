
static TCPS_SRV *tcpsforcast = NULL;
static TCP_STREAM *tcpcforcast = NULL;


//**********************************************************************************************************************************************//
//Main Function - EL04_01: TCP Server Connection Lean input weather
//**********************************************************************************************************************************************//
void comin_libsuper000(COMIN_LIBSUPER000 *io)
{
	//Variable Input
	//**************************************************************************//
	BIT in01 = 0;

	//Settins
	//**************************************************************************//
	FL poort = 59887;
	FL bytesIn = 0;
	FL bytesOut = 0;

	//Read Input/Outputs
	//**************************************************************************//
	in01 = *io->Input01;

	//Buffer
	//**************************************************************************//

	UC buf1[256];
	UC buf2[256];

	//Set NULL
	//**************************************************************************//
	if (PLUGIN_GetStartFlag())
	{
		*io->__s01 = 0;
		*io->__s02 = 0;
		*io->__se01 = 0;
		*io->__se02 = 0;
		*io->__se03 = 0;
		*io->__se04 = 0;
		*io->__se05 = 0;
		*io->__se06 = 0;
		*io->__se07 = 0;
		*io->__se08 = 0;
		*io->__se09 = 0;
		*io->__se10 = 0;
		*io->__se11 = 0;
		*io->__se12 = 0;
		*io->__se13 = 0;
		*io->__se14 = 0;
		*io->__se15 = 0;
		*io->__se16 = 0;
		*io->__se17 = 0;
		*io->__se18 = 0;
		*io->__se19 = 0;
		*io->__se20 = 0;
		*io->__se21 = 0;
		*io->__se22 = 0;
		*io->__se23 = 0;
		*io->__se24 = 0;
		*io->__see02 = 0;
		*io->__see03 = 0;

		memset(buf1, 0, sizeof(buf1));
		memset(buf2, 0, sizeof(buf2));
	}

	//Initialisation socket
	//**************************************************************************//
	if (in01 > 0 && tcpsforcast == 0)
	{
		tcpsforcast = TCPSSRV_CreateServer(poort);//TCPS_SRV*   TCPSSRV_CreateServer    (int iPort);
	}
	else if (tcpsforcast != 0)
	{
		if (TCPSSRV_AcceptRequested(tcpsforcast))
		{
			tcpcforcast = TCPSSRV_Accept(tcpsforcast, 10000);// TCP_STREAM* TCPSSRV_Accept(TCPS_SRV* pTCPSSRV, int iTimeoutMS);

			if (tcpcforcast != 0)
			{
				if (TCPS_ConnectNblkComplete(tcpcforcast) == 0)
				{
					if (TCPS_GetRemotePort(tcpcforcast) != 0)
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
			*io->__s02 = sizeof(buf1);

			//Casting
			//**************************************************************************//
			bytesIn = TCPS_ReceiveData(tcpcforcast, buf1, sizeof(buf1) + 1, 1000);
			sscanf(buf1, "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", &*io->__se01, &*io->__se02, &*io->__se03, &*io->__se04, &*io->__se05, &*io->__se06, &*io->__se07, &*io->__se08, &*io->__se09, &*io->__se10, &*io->__se11, &*io->__se12, &*io->__se13, &*io->__se14, &*io->__se15, &*io->__se16, &*io->__se17, &*io->__se18, &*io->__se19, &*io->__se20, &*io->__se21, &*io->__se22, &*io->__se23, &*io->__se24);

			*io->Output01 = *io->__se01;
			*io->Output02 = *io->__se02;
			*io->Output03 = *io->__se03;
			*io->Output04 = *io->__se04;
			*io->Output05 = *io->__se05;
			*io->Output06 = *io->__se06;
			*io->Output07 = *io->__se07;
			*io->Output08 = *io->__se08;
			*io->Output09 = *io->__se09;
			*io->Output10 = *io->__se10;
			*io->Output11 = *io->__se11;
			*io->Output12 = *io->__se12;
			*io->Output13 = *io->__se13;
			*io->Output14 = *io->__se14;
			*io->Output15 = *io->__se15;
			*io->Output16 = *io->__se16;
			*io->Output17 = *io->__se17;
			*io->Output18 = *io->__se18;
			*io->Output19 = *io->__se19;
			*io->Output20 = *io->__se20;
			*io->Output21 = *io->__se21;
			*io->Output22 = *io->__se22;
			*io->Output23 = *io->__se23;
			*io->Output24 = *io->__se24;


			UC *pos = buf2;
			memset(pos, 0, sizeof(buf2));
			memset(buf2, 0, sizeof(buf2));

			pos += sprintf(pos, "Dataoverdracht gereed");

			*io->__see02 = sizeof(buf2) + 1;

			if (bytesIn > 0)
			{
				while (*io->__see02 > 0)
				{
					bytesOut = TCPS_SendData(tcpcforcast, buf2, sizeof(buf2) + 1);
					*io->__see03 = bytesOut;
					*io->__see02 -= *io->__see03;
				}
			}


			TCPSSRV_RemoveServer(&tcpsforcast);
			TCPS_Disconnect(&tcpcforcast);



			//Disconect and Close Socket
			//**************************************************************************//
			if (in01 == 0)
			{
				TCPSSRV_RemoveServer(&tcpsforcast);
				TCPS_Disconnect(&tcpcforcast);
				*io->__s01 = 0;
				*io->__s02 = 0;
				*io->__se01 = 0;
				*io->__se02 = 0;
				*io->__se03 = 0;
				*io->__se04 = 0;
				*io->__se05 = 0;
				*io->__se06 = 0;
				*io->__se07 = 0;
				*io->__se08 = 0;
				*io->__se09 = 0;
				*io->__se10 = 0;
				*io->__se11 = 0;
				*io->__se12 = 0;
				*io->__se13 = 0;
				*io->__se14 = 0;
				*io->__se15 = 0;
				*io->__se16 = 0;
				*io->__se17 = 0;
				*io->__se18 = 0;
				*io->__se19 = 0;
				*io->__se20 = 0;
				*io->__se21 = 0;
				*io->__se22 = 0;
				*io->__se23 = 0;
				*io->__se24 = 0;
			}
		}
		else if (in01 == 0)
		{
			TCPSSRV_RemoveServer(&tcpsforcast);//void        TCPSSRV_RemoveServer    (TCPS_SRV** ppTCPSSRV);
			TCPS_Disconnect(&tcpcforcast);
			*io->__s01 = 0;
			*io->__s02 = 0;
			*io->__se01 = 0;
			*io->__se02 = 0;
			*io->__se03 = 0;
			*io->__se04 = 0;
			*io->__se05 = 0;
			*io->__se06 = 0;
			*io->__se07 = 0;
			*io->__se08 = 0;
			*io->__se09 = 0;
			*io->__se10 = 0;
			*io->__se11 = 0;
			*io->__se12 = 0;
			*io->__se13 = 0;
			*io->__se14 = 0;
			*io->__se15 = 0;
			*io->__se16 = 0;
			*io->__se17 = 0;
			*io->__se18 = 0;
			*io->__se19 = 0;
			*io->__se20 = 0;
			*io->__se21 = 0;
			*io->__se22 = 0;
			*io->__se23 = 0;
			*io->__se24 = 0;
		}
	}
}








