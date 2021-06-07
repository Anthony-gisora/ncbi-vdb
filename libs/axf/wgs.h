/*===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 */

typedef struct WGS WGS;
struct WGS {
    struct VCursor const *curs;
    uint32_t colID;
};

char const *WGS_Scheme(void);
unsigned WGS_splitName(int64_t *prow, unsigned const namelen, char const *name);
unsigned WGS_getBases(WGS *self, uint8_t *dst, unsigned start, unsigned len, int64_t row);
rc_t WGS_reopen(WGS *self, VDBManager const *mgr, VPath const *url, unsigned seq_id_len, char const *seq_id);
void WGS_close(WGS *self);
rc_t WGS_Init(WGS *self, VDatabase const *db);
