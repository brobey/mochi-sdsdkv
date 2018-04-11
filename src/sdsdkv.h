/*
 * Copyright (c) 2018      Los Alamos National Security, LLC
 *                         All rights reserved.
 *
 * This file is part of the sdsdkv project. See the LICENSE file at the
 * top-level directory of this distribution.
 */

/**
 * @file sdsdkv.h
 */

#pragma once

// For exported MPI types.
#include "mpi.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Convenience definition (in case anyone needs this). */
#define SDSDKV 1

/** Opaque sdsdkv context. */
struct sdsdkv;
/** Convenience typedef. */
typedef struct sdsdkv sdsdkv_t;
/** External context type. */
typedef sdsdkv_t* sdsdkv_context;

enum {
    /** Success. */
    SDSDKV_SUCCESS = 0,
    /** Success, but already done. */
    SDSDKV_SUCCESS_ALREADY_DONE,
    /** General error. */
    SDSDKV_ERR,
    /** System error. */
    SDSDKV_ERR_SYS,
    /** Out of resources error. */
    SDSDKV_ERR_OOR,
    /** Invalid argument provided to library. */
    SDSDKV_ERR_INVLD_ARG,
    /** Invalid configuration provided to library. */
    SDSDKV_ERR_INVLD_CONFIG,
    /** Library call before sdsdkv_create was called. */
    SDSDKV_ERR_CALL_BEFORE_INIT,
    /** MPI error. */
    SDSDKV_ERR_MPI,
    /** Action not supported. */
    SDSDKV_ERR_NOT_SUPPORTED,
    /** The thing that you were looking for wasn't found. */
    SDSDKV_ERR_NOT_FOUND
};

////////////////////////////////////////////////////////////////////////////////
// NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE //
////////////////////////////////////////////////////////////////////////////////
// If you update sdsdkv_config_*, please update valid_config().

/** Defines types of supported process personalities. */
enum sdsdkv_config_personality {
    /** Client personality. */
    SDSDKV_PERSONALITY_CLIENT = 0,
    /** Server personality. */
    SDSDKV_PERSONALITY_SERVER
};

/** Defines types of supported key hashing algorithms. */
enum sdsdkv_config_hashing {
    /** ch-placement. */
    SDSDKV_HASHING_CH_PLACEMENT = 0
};

// TODO(skg) Export DB type configury for back-end store?

/** Configuration struct. */
typedef struct sdsdkv_config {
    /** Communicator over which infrastructure will be created. */
    MPI_Comm init_comm;
    /** Process personality. */
    sdsdkv_config_personality personality;
    /** Hashing back-end. */
    sdsdkv_config_hashing hash_be;
} sdsdkv_config;

/**
 *
 */
int
sdsdkv_create(
    sdsdkv_context *c,
    sdsdkv_config *config
);

/**
 *
 */
int
sdsdkv_destroy(
    sdsdkv_context c
);

#ifdef __cplusplus
}
#endif

/*
 * vim: ft=cpp ts=4 sts=4 sw=4 expandtab
 */
