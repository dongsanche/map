/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "icar-helper.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
#include "ns3/icar.h"

#include "ns3/callback.h"
#include "ns3/udp-l4-protocol.h"


namespace ns3 {

IcarHelper::IcarHelper ()
{
  m_agentFactory.SetTypeId ("ns3::icar::RoutingProtocol");
}

IcarHelper::IcarHelper (const IcarHelper &o)
  : m_agentFactory (o.m_agentFactory)
{
}

IcarHelper*
IcarHelper::Copy (void) const
{
  return new IcarHelper (*this);
}

Ptr<Ipv4RoutingProtocol>
IcarHelper::Create (Ptr<Node> node) const
{
  Ptr<icar::RoutingProtocol> agent = m_agentFactory.Create<icar::RoutingProtocol> ();
  node->AggregateObject (agent);

  return agent;
}

void IcarHelper::Install (NodeContainer c) const
{
  // NodeContainer c = NodeContainer::GetGlobal ();
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      Ptr<Node> node = (*i);
      Ptr<UdpL4Protocol> udp = node->GetObject<UdpL4Protocol> ();
      Ptr<icar::RoutingProtocol> icar = node->GetObject<icar::RoutingProtocol> ();
      icar->SetDownTarget (udp->GetDownTarget ());
      udp->SetDownTarget (MakeCallback(&icar::RoutingProtocol::AddHeader, icar));
    }


}




void
IcarHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

}

