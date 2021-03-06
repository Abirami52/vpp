/*
 * Copyright (c) 2020 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * @brief The NAT44 inline functions
 */
#ifndef included_nat_inlines_h__
#define included_nat_inlines_h__

static_always_inline u32
ip_proto_to_nat_proto (u8 ip_proto)
{
  u32 nat_proto = ~0;

  nat_proto = (ip_proto == IP_PROTOCOL_UDP) ? NAT_PROTOCOL_UDP : nat_proto;
  nat_proto = (ip_proto == IP_PROTOCOL_TCP) ? NAT_PROTOCOL_TCP : nat_proto;
  nat_proto = (ip_proto == IP_PROTOCOL_ICMP) ? NAT_PROTOCOL_ICMP : nat_proto;
  nat_proto = (ip_proto == IP_PROTOCOL_ICMP6) ? NAT_PROTOCOL_ICMP : nat_proto;

  return nat_proto;
}

static_always_inline u8
nat_proto_to_ip_proto (nat_protocol_t nat_proto)
{
  u8 ip_proto = ~0;

  ip_proto = (nat_proto == NAT_PROTOCOL_UDP) ? IP_PROTOCOL_UDP : ip_proto;
  ip_proto = (nat_proto == NAT_PROTOCOL_TCP) ? IP_PROTOCOL_TCP : ip_proto;
  ip_proto = (nat_proto == NAT_PROTOCOL_ICMP) ? IP_PROTOCOL_ICMP : ip_proto;

  return ip_proto;
}

static_always_inline u8
icmp_type_is_error_message (u8 icmp_type)
{
  switch (icmp_type)
    {
    case ICMP4_destination_unreachable:
    case ICMP4_time_exceeded:
    case ICMP4_parameter_problem:
    case ICMP4_source_quench:
    case ICMP4_redirect:
    case ICMP4_alternate_host_address:
      return 1;
    }
  return 0;
}

#endif /* included_nat_inlines_h__ */
/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
