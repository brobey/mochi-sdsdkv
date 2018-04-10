/*
 * Copyright (c) 2018      Los Alamos National Security, LLC
 *                         All rights reserved.
 *
 * This file is part of the sdsdkv project. See the LICENSE file at the
 * top-level directory of this distribution.
 */

/**
 * @file sdsdkv.cc
 */

#include "sdsdkv.h"
#include "sdsdkv-mpi.h"

#include <iostream>

/** Type definition. */
struct sdsdkv {
    //
    sdsdkv_mpi *mpi;
    //
    static int
    create(
        sdsdkv_context *c,
        MPI_Comm c_comm
    ) {
        if (!c) return SDSDKV_ERR_INVLD_ARG;

        sdsdkv *tc = (sdsdkv *)calloc(1, sizeof(*tc));
        if (!tc) return SDSDKV_ERR_OOR;

        int erc = sdsdkv_mpi::create(&(tc->mpi), c_comm);
        if (erc != SDSDKV_SUCCESS) {
            destroy(tc);
            return erc;
        }

        *c = tc;

        return SDSDKV_SUCCESS;
    }
    //
    static int
    destroy(
        sdsdkv_context c
    ) {
        if (c) {
            sdsdkv_mpi::destroy(c->mpi);
            free(c);
        }

        return SDSDKV_SUCCESS;
    }
    //
    sdsdkv(void) = delete;
    //
    ~sdsdkv(void) = delete;
};

////////////////////////////////////////////////////////////////////////////////
int
sdsdkv_create(
    sdsdkv_context *c,
    MPI_Comm c_comm
) {
    return sdsdkv::create(c, c_comm);
}

////////////////////////////////////////////////////////////////////////////////
int
sdsdkv_destroy(
    sdsdkv_context c
) {
    return sdsdkv::destroy(c);
}
