/*++

Copyright (c) 1992  Microsoft Corporation

Module Name:

    stats.c

Abstract:

    Implements the stats command.

Author:

    Keith Moore (keithmo) 06-May-1996

Environment:

    User Mode.

Revision History:

--*/


#include "afdkdp.h"
#pragma hdrstop


//
//  Public functions.
//

DECLARE_API( stats )

/*++

Routine Description:

    Dumps the debug-only AFD statistic counters.

Arguments:

    None.

Return Value:

    None.

--*/

{
    AFD_QUOTA_STATS quotaStats;
    AFD_HANDLE_STATS handleStats;
    AFD_QUEUE_STATS queueStats;
    AFD_CONNECTION_STATS connectionStats;
    DWORD address;
    ULONG result;

    //
    // Dump the quota statistics.
    //

    address = GetExpression( "afd!AfdQuotaStats" );

    if( address == 0 ) {

        dprintf( "cannot find afd!AfdQuotaStats\n" );

    } else {

        if( ReadMemory(
                address,
                &quotaStats,
                sizeof(quotaStats),
                &result
                ) ) {

            dprintf(
                "AfdQuotaStats:\n"
                );

            dprintf(
                "    Charged  = %s\n",
                LongLongToString( quotaStats.Charged.QuadPart )
                );

            dprintf(
                "    Returned = %s\n",
                LongLongToString( quotaStats.Returned.QuadPart )
                );

            dprintf( "\n" );

        } else {

            dprintf(
                "stats: cannot read afd!AfdQuotaStats @ %08lx\n",
                address
                );

        }

    }

    //
    // Dump the handle statistics.
    //

    address = GetExpression( "afd!AfdHandleStats" );

    if( address == 0 ) {

        dprintf( "cannot find afd!AfdHandleStats\n" );

    } else {

        if( ReadMemory(
                address,
                &handleStats,
                sizeof(handleStats),
                &result
                ) ) {

            dprintf(
                "AfdHandleStats:\n"
                );

            dprintf(
                "    AddrOpened = %lu\n",
                handleStats.AddrOpened
                );

            dprintf(
                "    AddrClosed = %lu\n",
                handleStats.AddrClosed
                );

            dprintf(
                "    AddrRef    = %lu\n",
                handleStats.AddrRef
                );

            dprintf(
                "    AddrDeref  = %lu\n",
                handleStats.AddrDeref
                );

            dprintf(
                "    ConnOpened = %lu\n",
                handleStats.ConnOpened
                );

            dprintf(
                "    ConnClosed = %lu\n",
                handleStats.ConnClosed
                );

            dprintf(
                "    ConnRef    = %lu\n",
                handleStats.ConnRef
                );

            dprintf(
                "    ConnDeref  = %lu\n",
                handleStats.ConnDeref
                );

            dprintf(
                "    FileRef    = %lu\n",
                handleStats.FileRef
                );

            dprintf(
                "    FileDeref  = %lu\n",
                handleStats.FileDeref
                );

            dprintf( "\n" );

        } else {

            dprintf(
                "stats: cannot read afd!AfdHandleStats @ %08lx\n",
                address
                );

        }

    }

    //
    // Dump the queue statistics.
    //

    address = GetExpression( "afd!AfdQueueStats" );

    if( address == 0 ) {

        dprintf( "cannot find afd!AfdQueueStats\n" );

    } else {

        if( ReadMemory(
                address,
                &queueStats,
                sizeof(queueStats),
                &result
                ) ) {

            dprintf(
                "AfdQueueStats:\n"
                );

            dprintf(
                "    AfdWorkItemsQueued    = %lu\n",
                queueStats.AfdWorkItemsQueued
                );

            dprintf(
                "    ExWorkItemsQueued     = %lu\n",
                queueStats.ExWorkItemsQueued
                );

            dprintf(
                "    WorkerEnter           = %lu\n",
                queueStats.WorkerEnter
                );

            dprintf(
                "    WorkerLeave           = %lu\n",
                queueStats.WorkerLeave
                );

            dprintf(
                "    AfdWorkItemsProcessed = %lu\n",
                queueStats.AfdWorkItemsProcessed
                );

            dprintf(
                "    AfdWorkerThread       = %08lx\n",
                queueStats.AfdWorkerThread
                );

            dprintf( "\n" );

        } else {

            dprintf(
                "stats: cannot read afd!AfdQueueStats @ %08lx\n",
                address
                );

        }

    }

    //
    // Dump the queue statistics.
    //

    address = GetExpression( "afd!AfdConnectionStats" );

    if( address == 0 ) {

        dprintf( "cannot find afd!AfdConnectionStats\n" );

    } else {

        if( ReadMemory(
                address,
                &connectionStats,
                sizeof(connectionStats),
                &result
                ) ) {

            dprintf(
                "AfdConnectionStats:\n"
                );

            dprintf(
                "    ConnectedReferencesAdded      = %lu\n",
                connectionStats.ConnectedReferencesAdded
                );

            dprintf(
                "    ConnectedReferencesDeleted    = %lu\n",
                connectionStats.ConnectedReferencesDeleted
                );

            dprintf(
                "    GracefulDisconnectsInitiated  = %lu\n",
                connectionStats.GracefulDisconnectsInitiated
                );

            dprintf(
                "    GracefulDisconnectsCompleted  = %lu\n",
                connectionStats.GracefulDisconnectsCompleted
                );

            dprintf(
                "    GracefulDisconnectIndications = %lu\n",
                connectionStats.GracefulDisconnectIndications
                );

            dprintf(
                "    AbortiveDisconnectsInitiated  = %lu\n",
                connectionStats.AbortiveDisconnectsInitiated
                );

            dprintf(
                "    AbortiveDisconnectsCompleted  = %lu\n",
                connectionStats.AbortiveDisconnectsCompleted
                );

            dprintf(
                "    AbortiveDisconnectIndications = %lu\n",
                connectionStats.AbortiveDisconnectIndications
                );

            dprintf( "\n" );

        } else {

            dprintf(
                "stats: cannot read afd!AfdConnectionStats @ %08lx\n",
                address
                );

        }

    }

}   // stats

