//
//  parser.h
//  HeaderDumper
//
//  Created by Gabriele Biondo on 17/05/2020.
//  Copyright © 2020 Gabriele Biondo. All rights reserved.
//

#ifndef parser_h
#define parser_h

#include <stdio.h>
#include <mach-o/loader.h>
#include <mach-o/swap.h>
#include <mach-o/fat.h>

void            parseFlags          (uint32_t flags);
void            parseFileType       (uint32_t fileType);
void            parseCPUType        (cpu_type_t cputype);
void            parseCPUSubtype     (cpu_subtype_t subtype);
#endif /* parser_h */
