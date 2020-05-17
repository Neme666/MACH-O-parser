//
//  parser.c
//  HeaderDumper
//
//  Created by Gabriele Biondo on 17/05/2020.
//  Copyright © 2020 Gabriele Biondo. All rights reserved.
//

#include "parser.h"
void parseFlags (uint32_t flags){
    printf("flags: %d\n",flags);
    if (flags >= MH_DYLIB_IN_CACHE){
        printf("MH_DYLIB_IN_CACHE\t\t%X\n",MH_DYLIB_IN_CACHE);
        printf("Only for use on dylibs. When this bit is set, the dylib is part of the dyld shared cache, rather than loose in the filesystem");
        flags -=MH_DYLIB_IN_CACHE;
        printf("\nflags is now %d\n",flags);
        
    }
    
    if (flags >= MH_SIM_SUPPORT){
        printf("MH_SIM_SUPPORT\t\t%X\n",MH_SIM_SUPPORT);
        printf("Allow LC_MIN_VERSION_MACOS and LC_BUILD_VERSION load commands with the platforms macOS, iOSMac, iOSSimulator, tvOSSimulator and watchOSSimulator");
        flags -=MH_SIM_SUPPORT;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_NLIST_OUTOFSYNC_WITH_DYLDINFO){
        printf("MH_NLIST_OUTOFSYNC_WITH_DYLDINFO\t\t%X\n",MH_NLIST_OUTOFSYNC_WITH_DYLDINFO);
        printf("The external symbols listed in the nlist symbol table do not include all the symbols listed in the dyld info");
        flags -=MH_NLIST_OUTOFSYNC_WITH_DYLDINFO;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_APP_EXTENSION_SAFE){
        printf("MH_APP_EXTENSION_SAFE\t\t%X\n",MH_APP_EXTENSION_SAFE);
        printf("The code was linked for use in an application extension");
        flags -=MH_APP_EXTENSION_SAFE;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_NO_HEAP_EXECUTION){
        printf("MH_NO_HEAP_EXECUTION\t\t%X\n",MH_NO_HEAP_EXECUTION);
        printf("When this bit is set, the OS will run the main executable with a non-executable heap even on platforms (e.g. i386) that don't require it. Only used in MH_EXECUTE filetypes");
        flags -=MH_NO_HEAP_EXECUTION;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_HAS_TLV_DESCRIPTORS){
        printf("MH_HAS_TLV_DESCRIPTORS\t\t%X\n",MH_HAS_TLV_DESCRIPTORS);
        printf("Contains a section of type S_THREAD_LOCAL_VARIABLES");
        flags -=MH_HAS_TLV_DESCRIPTORS;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_DEAD_STRIPPABLE_DYLIB){
        printf("MH_DEAD_STRIPPABLE_DYLIB\t\t%X\n",MH_DEAD_STRIPPABLE_DYLIB);
        printf("Only for use on dylibs. When linking against a dylib that has this bit set, the static linker will automatically not create a LC_LOAD_DYLIB load command to the dylib if no symbols are being referenced from the dylib");
        flags -=MH_DEAD_STRIPPABLE_DYLIB;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_PIE){
        printf("MH_PIE\t\t%X\n",MH_PIE);
        printf("When this bit is set, the OS will load the main executable at a random address. Only used in MH_EXECUTE filetypes");
        flags -=MH_PIE;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_NO_REEXPORTED_DYLIBS){
        printf("MH_NO_REEXPORTED_DYLIBS\t\t%X\n",MH_NO_REEXPORTED_DYLIBS);
        printf("When this bit is set on a dylib, the static linker does not need to examine dependent dylibs to see if any are re-exported");
        flags -=MH_NO_REEXPORTED_DYLIBS;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_SETUID_SAFE){
        printf("MH_SETUID_SAFE\t\t%X\n",MH_SETUID_SAFE);
        printf("When this bit is set, the binary declares it is safe for use in processes when issetugid() is true");
        flags -=MH_SETUID_SAFE;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_ROOT_SAFE){
        printf("MH_ROOT_SAFE\t\t%X\n",MH_ROOT_SAFE);
        printf("When this bit is set, the binary declares it is safe for use in processes with uid zero");
        flags -=MH_ROOT_SAFE;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_ALLOW_STACK_EXECUTION){
        printf("MH_ALLOW_STACK_EXECUTION\t\t%X\n",MH_ALLOW_STACK_EXECUTION);
        printf("When this bit is set, all stacksin the task will be given stack execution privilege.Only used in MH_EXECUTE filetypes");
        flags -=MH_ALLOW_STACK_EXECUTION;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_BINDS_TO_WEAK){
        printf("MH_BINDS_TO_WEAK\t\t%X\n",MH_BINDS_TO_WEAK);
        printf("the final linked image uses weak symbols");
        flags -=MH_BINDS_TO_WEAK;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_WEAK_DEFINES){
        printf("MH_WEAK_DEFINES\t\t%X\n",MH_WEAK_DEFINES);
        printf("the final linked image contains external weak symbols");
        flags -=MH_WEAK_DEFINES;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_CANONICAL){
        printf("MH_CANONICAL\t\t%X\n",MH_CANONICAL);
        printf("the binary has been canonicalized via the unprebind operation");
        flags -=MH_CANONICAL;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_SUBSECTIONS_VIA_SYMBOLS){
        printf("MH_SUBSECTIONS_VIA_SYMBOLS\t\t%X\n",MH_SUBSECTIONS_VIA_SYMBOLS);
        printf("safe to divide up the sections into sub-sections via symbols for dead code stripping");
        flags -=MH_SUBSECTIONS_VIA_SYMBOLS;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_ALLMODSBOUND){
        printf("MH_ALLMODSBOUND\t\t%X\n",MH_ALLMODSBOUND);
        printf("indicates that this binary binds to all two-level namespace modules of its dependent libraries. only used when MH_PREBINDABLE and MH_TWOLEVEL are both set");
        flags -=MH_ALLMODSBOUND;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_PREBINDABLE){
        printf("MH_PREBINDABLE\t\t%X\n",MH_PREBINDABLE);
        printf("the final linked image uses weak symbols");
        flags -=MH_PREBINDABLE;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_NOFIXPREBINDING){
        printf("MH_NOFIXPREBINDING\t\t%X\n",MH_NOFIXPREBINDING);
        printf("do not have dyld notify the prebinding agent about this executable");
        flags -=MH_NOFIXPREBINDING;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_NOMULTIDEFS){
        printf("MH_NOMULTIDEFS\t\t%X\n",MH_NOMULTIDEFS);
        printf("this umbrella guarantees no multiple defintions of symbols in its sub-images so the two-level namespace hints can always be used");
        flags -=MH_NOMULTIDEFS;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_FORCE_FLAT){
        printf("MH_FORCE_FLAT\t\t%X\n",MH_FORCE_FLAT);
        printf("the executable is forcing all images to use flat name space bindings");
        flags -=MH_FORCE_FLAT;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_TWOLEVEL){
        printf("MH_TWOLEVEL\t\t%X\n",MH_TWOLEVEL);
        printf("the image is using two-level name space bindings");
        flags -=MH_TWOLEVEL;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_LAZY_INIT){
        printf("MH_LAZY_INIT\t\t%X\n",MH_LAZY_INIT);
        printf("the shared library init routine is to be run lazily via catching memory faults to its writeable segments (obsolete)");
        flags -=MH_LAZY_INIT;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_SPLIT_SEGS){
        printf("MH_SPLIT_SEGS\t\t%X\n",MH_SPLIT_SEGS);
        printf("the file has its read-only and read-write segments split");
        flags -=MH_SPLIT_SEGS;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_PREBOUND){
        printf("MH_PREBOUND\t\t%X\n",MH_PREBOUND);
        printf("the file has its dynamic undefined references prebound");
        flags -=MH_PREBOUND;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_BINDATLOAD){
        printf("MH_BINDATLOAD\t\t%X\n",MH_BINDATLOAD);
        printf("the object file's undefined references are bound by the dynamic linker when loaded");
        flags -=MH_BINDATLOAD;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_DYLDLINK){
        printf("MH_DYLDLINK\t\t%X\n",MH_DYLDLINK);
        printf("the object file is input for the dynamic linker and can't be statically link edited again");
        flags -=MH_DYLDLINK;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_INCRLINK){
        printf("MH_INCRLINK\t\t%X\n",MH_INCRLINK);
        printf("the object file is the output of an incremental link against a base file and can't be link edited again");
        flags -=MH_INCRLINK;
        printf("\nflags is now %d\n",flags);
    }
    
    if (flags >= MH_NOUNDEFS){
        printf("MH_NOUNDEFS\t\t%X\n",MH_NOUNDEFS);
        printf("the object file has no undefined references");
        flags -=MH_NOUNDEFS;
        printf("\nflags is now %d\n",flags);
    }
}

void parseFileType (uint32_t fileType){
    char * explanation;
    switch (fileType) {
        case MH_OBJECT:
            explanation = "relocatable object file";
            break;
        case MH_EXECUTE:
            explanation = "demand paged executable file";
            break;
        case MH_FVMLIB:
            explanation = "fixed VM shared library file";
            break;
        case MH_CORE:
            explanation = "core file";
            break;
        case MH_PRELOAD:
            explanation = "preloaded executable file";
            break;
        case MH_DYLIB:
            explanation = "dynamically bound shared library";
            break;
        case MH_DYLINKER:
            explanation = "dynamic link editor";
            break;
        case MH_BUNDLE:
            explanation = "dynamically bound bundle file";
            break;
        case MH_DYLIB_STUB:
            explanation = "shared library stub for static linking only, no section contents";
            break;
        case MH_DSYM:
            explanation = "companion file with only debug sections";
            break;
        case MH_KEXT_BUNDLE:
            explanation = "x86_64 kexts";
            break;
        default:
            explanation = "unknown file type";
    }
    
    printf("file type: %d - %s\n",fileType,explanation);
}

void parseCPUType (cpu_type_t cputype){
    char * explanation;
    switch (cputype) {
        case CPU_TYPE_ANY:
            explanation ="Any";
            break;
        case CPU_TYPE_VAX:
            explanation ="Vax";
            break;
        case CPU_TYPE_MC680x0:
            explanation ="MC680x0 ";
            break;
        case CPU_TYPE_X86:
            explanation ="X86";
            break;
        case CPU_TYPE_X86_64:
            explanation ="X86/64";
            break;
        case CPU_TYPE_MC98000:
            explanation ="MC98000 ";
            break;
        case CPU_TYPE_HPPA:
            explanation ="HPPA";
            break;
        case CPU_TYPE_ARM:
            explanation ="ARM";
            break;
        case CPU_TYPE_ARM64:
            explanation ="ARM64";
            break;
        case CPU_TYPE_ARM64_32:
            explanation ="ARM64_32";
            break;
        case CPU_TYPE_MC88000:
            explanation ="MC88000";
            break;
        case CPU_TYPE_SPARC:
            explanation ="SPARC";
            break;
        case CPU_TYPE_I860:
            explanation ="I860";
            break;
        case CPU_TYPE_POWERPC:
            explanation ="POWERPC";
            break;
        case CPU_TYPE_POWERPC64:
            explanation ="POWERPC64";
            break;
            
        default:
            explanation ="Unknown CPU type";
            break;
    }
    printf("CPU type: %d - %s\n",cputype,explanation);
}

void parseCPUSubtype (cpu_subtype_t subtype){
    //at the moment, this program supports only intel processors
    //to do: other processors.
    printf("parsing subtype\n");
    char * explanation;
    switch (subtype) {
       case CPU_SUBTYPE_386:
            explanation="386";
            break;
        case CPU_SUBTYPE_486:
            explanation="486";
            break;
        case CPU_SUBTYPE_486SX:
            explanation="486 SX";
            break;
        case CPU_SUBTYPE_PENT:
            explanation="Pentium";
            break;
        case CPU_SUBTYPE_PENTPRO:
            explanation="Pentium pro";
            break;
        case CPU_SUBTYPE_PENTII_M3:
            explanation="Pentium M3";
            break;
        case CPU_SUBTYPE_PENTII_M5:
            explanation="Pentium M5";
            break;
        case CPU_SUBTYPE_CELERON:
            explanation="Celeron";
            break;
        case CPU_SUBTYPE_CELERON_MOBILE:
            explanation="Celeron mobile";
            break;
        case CPU_SUBTYPE_PENTIUM_3:
            explanation="Pentium 3";
            break;
        case CPU_SUBTYPE_PENTIUM_3_M:
            explanation="Pentium 3M";
            break;
        case CPU_SUBTYPE_PENTIUM_3_XEON:
            explanation="Pentium 3 Xeon";
            break;
        case CPU_SUBTYPE_PENTIUM_M:
            explanation="Pentium M";
            break;
        case CPU_SUBTYPE_PENTIUM_4:
            explanation="Pentium 4";
            break;
        case CPU_SUBTYPE_PENTIUM_4_M:
            explanation="Pentium 4M";
            break;
        case CPU_SUBTYPE_ITANIUM:
            explanation="Itanium";
            break;
        case CPU_SUBTYPE_ITANIUM_2:
            explanation="Itanium 2";
            break;
        case CPU_SUBTYPE_XEON:
            explanation="Xeon";
            break;
        case CPU_SUBTYPE_XEON_MP:
            explanation="Xeon MP";
            break;
        case CPU_SUBTYPE_INTEL_FAMILY_MAX:
            explanation="Intel Family Max";
            break;
        case CPU_SUBTYPE_INTEL_MODEL_ALL:
            explanation="Intel";
            break;
      
        case CPU_THREADTYPE_INTEL_HTT:
            explanation="Intel HTT";
            break;
            
        default:
            explanation="Unknown CPU subtype";
            break;
    }
    printf("CPU subtype: %d - %s\n",subtype,explanation);
}
