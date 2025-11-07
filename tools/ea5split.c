#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

char header[128]=" TIFILES";
char empty_sector[256];

void write16(FILE* f,int v) {
	char c[2];
	c[0]=v>>8;
	c[1]=v&0xFF;
	fwrite(c,2,1,f);
}

void generate_header(int sectors,char eof_offset) {
	header[0]=7;
	int i;
	for(i=8;i<=128;i++)header[i]=0;
	header[8]=sectors/256;
	header[9]=sectors&0xFF;
	header[10]=1;
	header[12]=eof_offset;
}

void str_toupper(char* s) {
	int l=strlen(s);
	int i;
	for(i=0;i<l;i++)s[i]=toupper(s[i]);
}

int main(int argc,char** argv) {
	if(argc!=2) {
		printf("Usage:\n");
		printf("ea5split <ea5_file>\n");
		return(1);
	}

	FILE* f;
	f=fopen(argv[1],"rb");
	if(f==NULL) {
		printf("Cannot open \"%s\"\n",argv[1]);
		return(1);
	}
	fseek(f,0,SEEK_END);
	int l=ftell(f);
	fseek(f,0,SEEK_SET);

    unsigned char* data=malloc(l);
	fread(data,l,1,f);
	fclose(f);

    // we sure like to malloc... ;)
	char* ext=strchr(argv[1],'.');
	char* name=malloc(strlen(argv[1])+2);
	strcpy(name,argv[1]);
	if(ext!=NULL)name[ext-argv[1]]='\0';
        strcat(name,"1");

	str_toupper(name);
	int name_l=strlen(name);
	char* filename=malloc(strlen(name)+1);
	int i,l2,l3,sect,i2,offset;
    int filecnt;
	for(i=0;i<256;i++)empty_sector[i]=0;
    offset = 0;
    filecnt = 0;

repeat_load:
    printf("Parsing data... ");

	int load_address=data[offset+4]*256+data[offset+5];
    int length = data[offset+2]*256+data[offset+3];
	int end_address=load_address+length-1;
    offset += 6;
    printf("got len 0x%04X, load 0x%04X\n", length, load_address);
    if ((load_address >= 0xa000) && (end_address > 0xffff)) {
        // high memory bank
		printf("Program loaded outside expansion RAM (start 0x%X - end 0x%X)\n", load_address, end_address);
		free(data);
		return(1);
	} else if ((load_address >= 0x2000) && (load_address < 0x4000) && (end_address > 0x3fff)) {
        // low memory bank
		printf("Program loaded outside expansion RAM (start 0x%X - end 0x%X)\n", load_address, end_address);
		free(data);
		return(1);
	} else if ((load_address < 0x2000) || ((load_address >= 0x4000) && (load_address < 0xa000))) {
        // no memory bank
		printf("Program loaded outside expansion RAM (start 0x%X - end 0x%X)\n", load_address, end_address);
		free(data);
		return(1);
	}

    while (length > 0) {
		strcpy(filename,name);

		l2=length;
		if(l2>0x2000-6) {
			l2=0x2000-6;
			l3=0x2000;
		} else {
            l3=l2+6;
        }
		if (l3%256) {
            sect=l3/256+1;
        } else {
            sect=l3/256;
        }
		generate_header(sect,l3%256);

		f=fopen(filename,"wb");
		if (f == NULL) {
			printf("cannot write to %s (code %d)\n", filename, errno);
			return 1;
		}
        printf("Writing %s (LOAD 0x%04X SIZE 0x%04X)\n", filename, load_address, l2);
        ++filecnt;
        if (filecnt > 4) {
            printf("Something went wrong, should not need more than 4 files.\n");
            return 1;
        }
		fwrite(header,128,1,f);
        if (offset+l2 >= l) {
            write16(f,0x0000);      // last file
        } else {
            write16(f,0xffff);      // not last
        }
		write16(f,l2);              // size
		write16(f,load_address);    // load address
		fwrite(data+offset,l2,1,f); // write the data
		l3=(l2+6)%256;
		if(l3)fwrite(empty_sector,256-l3,1,f);  // pad out to 256 bytes
		fclose(f);

		load_address+=l2;           // next load address
		offset+=l2;                 // next file offset
        length -= l2;               // count down length
		name[strlen(name)-1]++;     // update name
	}
    if (offset < l) {
        // should be a second header for low RAM, go reprocess
        goto repeat_load;
    }

	free(name);
	free(data);
	free(filename);

	return(0);
}
