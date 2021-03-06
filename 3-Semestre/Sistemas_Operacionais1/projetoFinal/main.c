#include <direct.h> // BIBLIOTECA DA MICROSOFT
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <VersionHelpers.h>	//N?O CONSIGO RODAR PQ N?O TENHO WINDOWS 1O -MARCEL
#include <time.h>

//LUIS - Renomear, mover, data, hora e sair.

void _CriaDirArc(char *p1,char *p2)
{
    char *dir = (char*)calloc(1,sizeof(char));
    FILE *arq;
    struct _finddata_t c_file;
    intptr_t hFile;

    if(strcmp(p1,"-d") == 0){
        strcat(dir, p2);
        //printf("%s", dir);		//Checagem de diret?rio -Marcel
        if( _mkdir(dir) == 0 )
            printf( "Diretorio %s criado com sucesso\n", p2);
        else
            printf("Diretorio j? existe\n");
    }
    else if(strcmp(p1,"-a") == 0){
        strcat(dir,p2);
        strcat(dir,".txt");

        if( (hFile = _findfirst( dir, &c_file )) == -1 ){
            arq = fopen(dir,"a+");
            if(arq != NULL)
                printf("Arquivo %s criado!\n", p2);
            else
                printf("Erro ao criar o arquivo %s\n", p2);
            fclose(arq);
            _findclose( hFile );
        }
        else{
            printf("Arquivo j? existe!\n");
            _findclose( hFile );
        }
    }
    else{
        printf("Parametro Invalido!\n");
    }
    free(dir);
}

void _Limpar(){
    system("CLS");
    printf("============= GLM OS - 1.6 =============\n");		//Toda vez que der CLS usa essa fun??o pra voltar com o nome do programa no topo -Marcel
}

void _InsereTexto(char* p1, char* p2){
    int i;
    struct _finddata_t c_file;
    intptr_t hFile;
    strcat(p2,".txt");
    if( (hFile = _findfirst( p2, &c_file )) == -1 ){
            printf("Arquivo n?o existe!\n");
            _findclose( hFile );
        }
        else{
            FILE *pont_arq;
            pont_arq = fopen(p2, "w");
            if(pont_arq == NULL)
            {
                printf("Erro na abertura do arquivo!");
            }
            else{
                fprintf(pont_arq, "%s", p1);
            }
            fclose(pont_arq);
            _findclose( hFile );
        }
}

void _ListarDir(){
    struct _finddata_t c_file;
    intptr_t hFile;

   if( (hFile = _findfirst( "*.*", &c_file )) == -1 )
      printf( "Diret?rio vazio!\n" );
   else
   {
      do {
            if(strcmp(c_file.name,"main.c") != 0 && strcmp(c_file.name,"main.exe") != 0 && strcmp(c_file.name,"main.o") != 0 &&  strcmp(c_file.name,".") != 0 && strcmp(c_file.name,"..") != 0)
                printf( " %s \n", c_file.name);
      } while( _findnext( hFile, &c_file ) == 0 );

      _findclose( hFile );
   }
}

void _Apagar(char* p1)	//DIRET?RIO
{
	if(_rmdir(p1)==0)
	{
		printf("Diret?rio excluido com sucesso!\n");
	}
	else
	{
		printf("Erro ao apagar diret?rio: ");
		if(errno == ENOTEMPTY)
		{
			printf("Diret?rio n?o est? vazio ou n?o ? um diret?rio!\n");
		}
		else if(errno == ENOENT)
		{
			printf("Diret?rio n?o encontrado!\n");
		}
		else{	printf("Erro desconhecido!\n");		}
	}
}

char * getdir() //Retorna um string que ? o diret?rio atual -Luis
{
    static char path[_MAX_DIR];

    _getcwd(path, _MAX_DIR);
    printf("Diret?rio atual: %s\n", path);
    return path;
}

int existe(char *par) //Checa se a pasta ou arquivo existe -Luis
{
    return _access(par, 00);
}

void _Renomear(char *old, char *newD)  //Renomeia pasta ou arquivo -Luis
{

    int result = rename(old, newD);
    if( result != 0 )
        printf( "N?o foi poss?vel renomear '%s'\n", old);
    else
        printf( "'%s' foi renomeado para '%s'\n", old, newD );

    //int _wrename(const wchar_t *p1, const wchar_t *p2);
    free(old); free(newD);
}

void _Mover(char *p1, char *p2)  //Move p1 para dentro de p2
{
	int result;
    //char* oldP2 = *p2; DEBUG
    //VERIFICA SE OS 2 EXISTEM
    if(existe(p1) != 0)
        printf("ERRO: N?o existe %s!\n", p1);
    if(existe(p2) != 0)
        printf("ERRO: N?o existe %s!\n", p2);


    /*printf("%s\n", p1); COMO FICOU O DIR NOVO PARA p2
    Se C:\pasta1 e C:\pasta2 -> C:\pasta1 e c:\pasta1\pasta2

    EDITA OS STRINGS*/
    strcat(p2, "\\");
    //printf("\n%s\n", p2); //Por que n?o printa?
    strcat(p2, p1);
    //printf("\n%s\n", p2);
	result = rename(p1, p2); //Tenta renomear, se houver erro retorna -1
	//printf("\nP1:%s\nP2:%s\n", p1, p2);


    if(result == -1)
        printf("ERRO ao mover '%s' para '%s'\n", p1, p2);
//        if(errno == EACCES)
//        {
//        	printf("EACCES");
//		}
//		else if(errno == EBUSY)
//		{
//			printf("EBUSY");
//		}
//		else if(errno == ENOTEMPTY)
//		{
//			printf("ENOTEMPTY");
//		}
//		else if(errno == EEXIST)
//		{
//			printf("EEXIST");
//		}
//		else if(errno == EINVAL)
//		{
//			printf("EINVAL");
//		}
//		else if(errno == EISDIR)
//		{
//			printf("EISDIR");
//		}
//		else if(errno == EMLINK)
//		{
//			printf("EMLINK");
//		}
//		else if(errno == ENOENT)
//		{
//			printf("ENOENT");
//		}
//		else if(errno == ENOSPC)
//		{
//			printf("ENOSPC");
//		}
//		else if(errno == EROFS)
//		{
//			printf("EROFS");
//		}
//		else if(errno == EXDEV)
//		{
//			printf("EXDEV");
//		}

    else
        printf("'%s' foi movido para '%s'\n", p1, p2);
    //free(p1);
	//free(p2);
}

void _Deletar(char* p1)		//Arquivo
{
	strcat(p1, ".txt");
	if(remove(p1)==0)
	{
		printf("Arquivo %s deletado com sucesso!\n", p1);
	}
	else{printf("Falha ao deletar arquivo!\n");	}
}

void _Ajuda()
{
	_Limpar();
	printf("\n\n\n|==============================================================================|\n");
	printf("|COMANDOS   |DESCRI??O                                                         |\n");
	printf("|==============================================================================|\n");
	printf("|CRIAR		|CRIA UM ARQUIVO OU DIRET?RIO                                  |\n");
	printf("|INSERIR	|INSERE UM TEXTO EM UM ARQUIVO                                 |\n");
	printf("|LISTAR		|LISTA ARQUIVOS E DIRET?RIOS DA PASTA                          |\n");
	printf("|APAGAR		|APAGA UM DIRETORIO                                            |\n");
	printf("|RENOMEAR	|RENOMEIA UM ARQUIVO OU DIRETORIO                              |\n");
	printf("|MOVER		|MOVE UM ARQUIVO OU DIRET?RIO                                  |\n");
	printf("|DELETAR	|DELETA UM DIRET?RIO                                           |\n");
	printf("|AJUDA		|LISTA TODOS OS COMANDOS DESTA TABELA JUNTAMENTE COM DESCRI??ES|\n");
	printf("|VER		|IMPRIME A VERS?O DO SISTEMA OPERACIONAL                       |\n");
	printf("|DATA		|IMPRIME A DATA DO SISTEMA OPERACIONAL                         |\n");
	printf("|HORA		|IMPRIME A HORA DO SISTEMA OPERACIONAL                         |\n");
	printf("|LIMPAR		|LIMPA O CONTE?DO ATUAL DA TELA                                |\n");
	printf("|SAIR		|FINALIZA O PROGRAMA                                           |\n");
}

void _Version()
{
    if	(!IsWindows10OrGreater())		printf("Seu sistema ? Windows 10\n");			//Vai verificar qual a vers?o com a biblioteca VersionHelpers -Marcel
	else if(!IsWindows8Point1OrGreater())	printf("Seu sistema ? Windows 8.1\n");
	else if(!IsWindows8OrGreater())			printf("Seu sistema ? Windows 8\n");
	else if(!IsWindows7SP1OrGreater())		printf("Seu sistema ? Windows 7 SP 1\n");
	else if(!IsWindows7OrGreater())			printf("Seu sistema ? Windows 7\n");
	else if(!IsWindowsVistaSP2OrGreater())	printf("Seu sistema ? Windows Vista SP 2\n");
	else if(!IsWindowsVistaSP1OrGreater())	printf("Seu sistema ? Windows Vista SP 1\n");
	else if(!IsWindowsVistaOrGreater())		printf("Seu sistema ? Windows Vista\n");
	else if(!IsWindowsXPSP3OrGreater())		printf("Seu sistema ? Windows XP SP 3\n");
	else if(!IsWindowsXPSP2OrGreater())		printf("Seu sistema ? Windows XP SP 2\n");
	else if(!IsWindowsXPSP1OrGreater())		printf("Seu sistema ? Windows XP SP 1\n");
	else if(!IsWindowsXPOrGreater())		printf("Seu sistema ? Windows XP\n");

}

void _Data(){
    time_t rawtime;
    struct tm * timeinfo;
    char *output;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf("Data: %d/%d/%d\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    //sprintf(output, "[%d %d %d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

void _Hora(){
    time_t rawtime;
    struct tm * timeinfo;
    char *output;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf("Hora: %d:%d:%d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}


void _Sair(){
    system("CLS");
    printf("Desligando");
    for(int i=0; i<3; i++)
    {
      	Sleep(250);
    	printf(".");
    	Sleep(250);
	}
    system("CLS");
    printf("Desligado");
    exit(0);
}

int main()
{
    char text[255];
    char *comand,*p1,*p2;
    int i,j,k,len,tamC,tamP1,tamP2,t=0;
    setlocale(LC_ALL, "");

    printf("\n  .g8\"\"\"bgd  `7MMF'      `7MMM.     ,MMF\'                .g8\"\"8q.    .M\"\"\"bgd \n.dP\'     `M    MM          MMMb    dPMM                .dP\'    `YM. ,MI    \"Y \ndM\'       `    MM          M YM   ,M MM                dM\'      `MM `MMb.     \nMM             MM          M  Mb  M\' MM                MM        MM   `YMMNq. \nMM.    `7MMF\'  MM      ,   M  YM.P\'  MM      mmmmm     MM.      ,MP .     `MM \n`Mb.     MM    MM     ,M   M  `YM\'   MM                `Mb.    ,dP\' Mb     dM \n  `\"bmmmdPY  .JMMmmmmMMM .JML. `\'  .JMML.                `\"bmmd\"\'   P\"Ybmmd\"\n           ");
    printf("\nCarregando");
    for(int i=0; i<2; i++)
    {
      	Sleep(250);
    	printf(".");
    	Sleep(250);
	}
    system("CLS");

    printf("============= GLM OS - 1.6 =============\n");
    while(1){
        tamC=0;tamP1=0;tamP2=0;len=0;

        printf(">>>");
        fflush(stdin);
        fgets(text,255,stdin);
        len = strlen(text);
//========================== SEPARAR PARAMETROS DOS COMANDOS ==========================================
        for(i=0; text[i]!= ' '; i++)
            tamC++;
        if(text[tamC+1] == '"'){
            for(i=tamC+2; text[i]!= '"'; i++)
                tamP1++;
            for(i=tamC+tamP1+4; text[i]!= '\0'; i++)
                tamP2++;
            t = 2;
        }
        else{
            for(i=tamC+1; text[i]!= ' '; i++)
                tamP1++;
            for(i=tamC+tamP1+2; text[i]!= '\0'; i++)
                tamP2++;
        }
//        for(i=0,j=0,k=0,t=0; i<len-1; i++,j++){
//            if(k==0 && text[i] != ' ' && t==0){
//                tamC++;
//            }
//            else if(k==1 && text[i] != ' ' && (t==0 || t==1)){
//                if(text[i] == '"'){
//                    t++;
//                }else{
//                    tamP1++;
//                }
//            }
//            else if(k==2 && text[i] != ' ' && t==2){
//                tamP2++;
//            }
//            else if(k==1 && t==1){
//                tamP1++;
//            }
//            else{
//                k++;
//                j--;
//            }
//        }
        tamP2 -= 1;
        printf("%d\n%d\n%d\n", tamC, tamP1, tamP2);
        comand = (char *) malloc(tamC*sizeof(char));
        p1 = (char *) malloc(tamP1*sizeof(char));
        p2 = (char *) malloc(tamP2*sizeof(char));

        for(i=0;i<tamC;i++)
            comand[i] = text[i];

        comand[tamC] = '\0';

        if(t==0){
            for(i=tamC+1,j=0; i<(tamC+tamP1+1); i++,j++)
                p1[j] = text[i];

            p1[tamP1] = '\0';

            for(i=tamC+tamP1+2,j=0;i<len;i++,j++)
                p2[j] = text[i];

            p2[tamP2] = '\0';
        }
        else{
            for(i=9,j=0; i<(tamC+tamP1+2); i++,j++)
                p1[j] = text[i];

            p1[tamP1] = '\0';

            for(i=tamC+tamP1+4,j=0;i<len;i++,j++)
                p2[j] = text[i];

            p2[tamP2] = '\0';
        }
        printf("%s\n%s\n%s\n", comand, p1, p2);
//=====================================================================================

        if(strcmp(comand,"CRIAR") == 0){
        	_CriaDirArc(p1,p2);                // OK
        }
        else if(strcmp(comand,"INSERIR") == 0){
            _InsereTexto(p1,p2);
        }
        else if(strcmp(comand,"LISTAR") == 0){
            _ListarDir();
        }
        else if(strcmp(comand,"APAGAR") == 0){
            _Apagar(p1);                        // OK
        }
        else if(strcmp(comand,"RENOMEAR") == 0){
            _Renomear(p1, p2);
        }
        else if(strcmp(comand,"MOVER") == 0){
            _Mover(p1, p2);
        }
        else if(strcmp(comand,"DELETAR") == 0){
            _Deletar(p1);                       // OK
        }
        else if(strcmp(comand,"AJUDA") == 0){
            _Ajuda();                           // OK
        }
        else if(strcmp(comand,"VER") == 0){
            _Version();                         // OK
        }
        else if(strcmp(comand,"DATA") == 0){
            _Data();                            // OK
        }
        else if(strcmp(comand,"HORA") == 0){
            _Hora();                            // OK
        }
        else if(strcmp(comand,"LIMPAR") == 0){
            _Limpar();                          // OK
        }
        else if(strcmp(comand,"SAIR") == 0){
            _Sair();				            // OK
        }
        else{
            printf("COMANDO INVALIDO!!\n");
        }
    free(comand);
    free(p1);
    free(p2);
    }
    return 0;
}
