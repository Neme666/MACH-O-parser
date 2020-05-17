//
//  main.m
//  HeaderDumper
//
//  Created by Gabriele Biondo on 16/05/2020.
//  Copyright © 2020 Gabriele Biondo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <mach-o/loader.h>
#include <mach-o/swap.h>
#include <mach-o/fat.h>
#include "parser.h"

#define     REQUIRED_ARGS   1
#define     NO_ERR          0
#define     NUM_PARAMS_ER   1
#define     CANT_OPN_FILE   2
#define     NO_MACH         3

#define     MAGIC_OFFSET    0


int             printUsage          (const char * v);
int             printHelp           (const char * v);
//int             dumpSegments    (FILE * objFile);
uint32_t        read_magic          (FILE *theFile, int offset);
int             isMachO             (uint32_t magic);
int             is64Tester          (uint32_t magic);
int             should_swap_bytes   (uint32_t magic);
int             is_fat              (uint32_t magic);
static void *   load_bytes          (FILE *obj_file, off_t offset, size_t size);
static void     dump_mach_header    (FILE *obj_file, off_t offset, bool is_64, bool is_swap);

//extern void     dump_segments   (FILE *obj_file);


int main(int argc, const char * argv[]) {
    int result = NO_ERR;

    if (argc < (1+REQUIRED_ARGS)){
        result = printUsage(argv[0]);
    }
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0){
        result = printHelp(argv[0]);
    }
    
    if (result == NO_ERR){
        const char *filename = argv[1];
        FILE *obj_file = fopen(filename, "rb");
        if (obj_file == NULL) {
            printf("'%s' could not be opened.\n", argv[1]);
            result = CANT_OPN_FILE;
        } else {
            uint32_t magic = read_magic(obj_file, MAGIC_OFFSET);
            result = isMachO(magic);
            if(result == NO_ERR){
                int byteArch = 32;
                int swapOrder = should_swap_bytes(magic);
                int isFat = is_fat(magic);
                if (is64Tester(magic))
                    byteArch = 64;
                printf("Mach-O file %d-bits\n",byteArch);
                printf("Magic Number:\\x%X\n",magic);
                if (swapOrder)
                    printf("Byte order must be swapped\n");
                else
                    printf("Byte order must not be swapped\n");
                if (isFat){
                    printf("Fat header\n");
                    
                }
                else{
                    printf("Slim header\n");
                    dump_mach_header(obj_file, 0, (byteArch == 64), (swapOrder == 1));
                }

            } else {
                printf("No Mach-O file\n");
            }
        }
    }
    
    return result;
}

int printUsage(const char * v){
    printf("Usage: %s <path to mach-o binary>\n", v);
    return NUM_PARAMS_ER;
}

int printHelp(const char * v){
    printf("Usage: %s <path to mach-o binary>\n", v);
    printf("Optional parameters:\n\t");
    printf("-h, --help: displays this message and quits\n");
    return NO_ERR;
}



//int dump_segments(FILE *obj_file) {
  //  int result = NO_ERR;
    
  //uint32_t magic = read_magic(obj_file, 0);
  //int is_64 = is_magic_64(magic);
  //int is_swap = should_swap_bytes(magic);
  //int fat = is_fat(magic);
  //if (fat) {
    //dump_fat_header(obj_file, is_swap);
  //} else {
    //dump_mach_header(obj_file, 0, is_64, is_swap);
  //}
    //return result;
//}

uint32_t read_magic(FILE *theFile, int offset) {
  uint32_t magic;
  fseek(theFile, offset, SEEK_SET);
  fread(&magic, sizeof(uint32_t), 1, theFile);
  return magic;
}

int isMachO(uint32_t magic){
    int result = 0;
    
    result = (magic == MH_MAGIC_64 ) || (magic == MH_MAGIC ) || (magic == MH_CIGAM_64 ) || (magic == MH_CIGAM );
    
    result = (result == 1?NO_ERR:NO_MACH);
    
    return result;
}

int is64Tester(uint32_t magic){
    int result = ((magic == MH_MAGIC_64) || (magic == MH_CIGAM_64));
    return result;
}

int should_swap_bytes(uint32_t magic) {
  return magic == MH_CIGAM || magic == MH_CIGAM_64;
}

int is_fat(uint32_t magic) {
  return magic == FAT_MAGIC || magic == FAT_CIGAM;
}

static void *load_bytes(FILE *obj_file, off_t offset, size_t size) {
  void *buf = calloc(1, size);
  fseek(obj_file, offset, SEEK_SET);//moves the file ptr offset bytes from the beginning
  fread(buf, size, 1, obj_file); //reads into buf size bytes as 1 element from objFile
  return buf;
}

static void dump_mach_header(FILE *obj_file, off_t offset, bool is_64, bool is_swap) {
    uint32_t ncmds;
    uint32_t flags;
    uint32_t fileType;
    cpu_type_t cputype;
    cpu_subtype_t subtype;
    off_t load_commands_offset = offset;
    size_t header_size = (is_64==1?sizeof(struct mach_header_64):sizeof(struct mach_header));
    if (is_64) {
        struct mach_header_64 * header = load_bytes(obj_file, offset, header_size);
        if (is_swap) {
            swap_mach_header_64(header, 0); //defined in swap.h
        }
        ncmds = header->ncmds;
        flags = header->flags;
        fileType = header->filetype;
        cputype = header->cputype;
        subtype = header->cpusubtype;
        load_commands_offset += header_size;
        printf("cpu type code: %d subtype: %u\n",header->cputype, header->cpusubtype);
        printf("number of load commands: %u\n",ncmds);
        printf("size of all load commands: %u\n",header->sizeofcmds);
        parseFileType(fileType);
        parseFlags(flags);
        parseCPUType(cputype);
        parseCPUSubtype(subtype);
        free(header);
    } else {
        struct mach_header *header = load_bytes(obj_file, offset, header_size);
        if (is_swap) {
          swap_mach_header(header, 0);
        }
        ncmds = header->ncmds;
        flags = header->flags;
        fileType = header->filetype;
        cputype = header->cputype;
        subtype = header->cpusubtype;
        load_commands_offset += header_size;
        printf("cpu type code: %d subtype: %u\n",header->cputype, header->cpusubtype);
        printf("number of load commands: %u\n",ncmds);
        printf("size of all load commands: %u\n",header->sizeofcmds);
        parseFileType(fileType);
        parseFlags(flags);
        parseCPUType(cputype);
        parseCPUSubtype(subtype);
        free(header);
    }

 /*

  dump_segment_commands(obj_file, load_commands_offset, is_swap, ncmds);*/
}

