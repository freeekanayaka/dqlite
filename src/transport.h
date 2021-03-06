/* Implementation of the raft_uv_transport interface, proxied by a dqlite
 * connection. */
#ifndef TRANSPORT_H_
#define TRANSPORT_H_

#include <raft/uv.h>

#include "../include/dqlite.h"

int raftProxyInit(struct raft_uv_transport *transport, struct uv_loop_s *loop);

void raftProxyClose(struct raft_uv_transport *transport);

/* Invoke the accept callback configured on the transport object. */
void raftProxyAccept(struct raft_uv_transport *transport,
		     unsigned id,
		     const char *address,
		     struct uv_stream_s *stream);

/* Set a custom connect function. */
void raftProxySetConnectFunc(struct raft_uv_transport *transport,
			     dqlite_connect connect,
			     void *data);

#endif /* TRANSPORT_H_*/
