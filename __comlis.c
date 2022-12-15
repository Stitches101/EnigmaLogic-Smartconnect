
//**********************************************************************************************************************************************//
//Main Function - EL04_01: Socket Listen
//**********************************************************************************************************************************************//

static SOCKET_BASE *socklis = NULL;
static TCPS_SRV *tcpslis = NULL;
static TCP_STREAM *tcpclis = NULL;


void com5_libsuper000(COM5_LIBSUPER000 *io)
{
	//Variable Input
	//**************************************************************************//
	BIT in01 = 0;


	//Variable Local
	//**************************************************************************//
	FL Group02;
	FL Adrid02;

	UI Count = 0;
	UI Count02 = 0;
	UI sort;

	//Settings
	//**************************************************************************//
	FL poort = 59891;
	FL bytesIn = 0;
	FL bytesOut = 0;
	UC remIP = 0;
	FL remPort = 0;

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

	UC buf1[256];
	UC buf2[256];
	UC buf3[256];

	//Initialisation socket
	//**************************************************************************//
	if (in01 > 0 && tcpslis == 0)
	{

		tcpslis = TCPSSRV_CreateServer(poort);//TCPS_SRV*   TCPSSRV_CreateServer    (int iPort);

	}
	else if (tcpslis != 0)
	{
		if (TCPSSRV_AcceptRequested(tcpslis))
		{

			*io->__s01 = 0;
			*io->__s02 = 0;
			*io->__s03 = 0;
			*io->__s04 = 0;
	

			tcpclis = TCPSSRV_Accept(tcpslis, 10000);// TCP_STREAM* TCPSSRV_Accept(TCPS_SRV* pTCPSSRV, int iTimeoutMS);

			if (tcpclis != 0)
			{
				if (TCPS_ConnectNblkComplete(tcpclis) == 0)
				{
					if (TCPS_GetRemotePort(tcpclis) != 0)
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
			bytesIn = TCPS_ReceiveData(tcpclis, buf3, sizeof(buf3) + 1, 1000); //int         TCPS_ReceiveData        (TCP_STREAM* pTCPS, char* cpBuffer, int iBufferSize, int iTimeoutMS);
			remPort = TCPS_GetRemotePort(tcpclis); //int         TCPS_GetRemotePort      (TCP_STREAM* pTCPS);
			remIP = TCPS_GetRemoteIP(tcpclis);//const char* TCPS_GetRemoteIP(TCP_STREAM* pTCPS);

			memset(buf1, 0, sizeof(buf1));
			memset(buf2, 0, sizeof(buf2));

			//message build
			UC *pos = buf1;
			memset(pos, 0, sizeof(buf1));
			UI idx2;
			UI idx3;

			pos += sprintf(pos, "start");
			pos += sprintf(pos, ", ");
			pos += sprintf(pos, "%c", remIP);
			pos += sprintf(pos, ", ");
			pos += sprintf(pos, "%.f", remPort);
			pos += sprintf(pos, ", ");
			pos += sprintf(pos, ", finish");
			pos += sprintf(pos, ", ");

			*io->__s02 = sizeof(buf1) + 1;

			if (bytesIn > 0)
			{
				while (*io->__s02 > 0)
				{
					bytesOut = TCPS_SendData(tcpclis, buf1, sizeof(buf1) + 1);//int         TCPS_SendData           (TCP_STREAM* pTCPS, const char* cpData, int iCount);
					*io->__s03 = bytesOut;
					*io->__s02 -= *io->__s03;
				}
			}


			socklis  = SOCKET_BASE_GenerateNewSocket();//SOCKET_BASE* SOCKET_BASE_GenerateNewSocket();
			SOCKET_BASE_connect(socklis, remIP, 59884);//SOCKET_BASE_connect(SOCKET_BASE *sbThisSocket, const char* cpHostIP, const int iPort)

			if (SOCKET_BASE_is_valid(socklis))
			{
				*io->__s02 = sizeof(buf1) + 1;
				if (bytesIn > 0)
				{
					while (*io->__s02 > 0)
					{
						bytesOut = SOCKET_BASE_SendData(socklis, buf1, sizeof(buf1) + 1); //aBOOL SOCKET_BASE_SendData(SOCKET_BASE *sbThisSocket, const char* cpData, int iCount)
						*io->__s03 = bytesOut;
						*io->__s02 -= *io->__s03;
					}
				}

			}




			//end message build
			SOCKET_BASE_RemoveSocket(&socklis);
			TCPSSRV_RemoveServer(&tcpslis);
			TCPS_Disconnect(&tcpclis);
		}
		//Disconect and Close Socket
		//**************************************************************************//
		if (in01 == 0)
		{
			TCPSSRV_RemoveServer(&tcpslis);
			TCPS_Disconnect(&tcpclis);
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
		TCPSSRV_RemoveServer(&tcpslis);//void        TCPSSRV_RemoveServer    (TCPS_SRV** ppTCPSSRV);
		TCPS_Disconnect(&tcpclis);
	}


}









