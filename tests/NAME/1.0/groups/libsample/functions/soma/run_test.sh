#!/bin/sh
INSTALL_PREFIX=${INSTALL_PREFIX:-/home/victor/Documentos/UFPE/UFPE/api-sanity-checker/Tutorial-API_SC}

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"$INSTALL_PREFIX" && ./test arg1 arg2 arg3 >output 2>&1
