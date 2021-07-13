/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef ICAR_HELPER_H
#define ICAR_HELPER_H

#include "ns3/icar.h"
#include "ns3/object-factory.h"
#include "ns3/node.h"
#include "ns3/node-container.h"
#include "ns3/ipv4-routing-helper.h"
#include <map>
#include <set>

namespace ns3 {

class IcarHelper : public Ipv4RoutingHelper
{
public:
  IcarHelper ();
  IcarHelper (const IcarHelper &);
  IcarHelper* Copy (void) const;
  virtual Ptr<Ipv4RoutingProtocol> Create (Ptr<Node> node) const;
  void Set (std::string name, const AttributeValue &value);
  void Install (NodeContainer c) const;

private:
  IcarHelper &operator = (const IcarHelper &);
  ObjectFactory m_agentFactory;
};

}

#endif /* ICAR_HELPER_H */

