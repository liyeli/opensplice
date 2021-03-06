/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2012 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef OSPL_DDS_TOPIC_DISCOVERY_HPP_
#define OSPL_DDS_TOPIC_DISCOVERY_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <spec/dds/topic/discovery.hpp>
#include <org/opensplice/core/exception_helper.hpp>

// Implementation

namespace dds { namespace topic {

template <typename TOPIC>
TOPIC discover(const dds::domain::DomainParticipant& dp,
    const std::string& name,
    const dds::core::Duration& timeout)
{
    return dds::core::null;
}

template <typename TOPICDATA, typename FwdIterator>
uint32_t discover(const dds::domain::DomainParticipant& dp, FwdIterator begin, uint32_t max_size)
{
    return 0;
}

template <typename TOPICDATA, typename BinIterator>
uint32_t discover(const dds::domain::DomainParticipant& dp, BinIterator begin)
{
    return 0;
}

void ignore(const dds::domain::DomainParticipant& dp,
    const dds::core::InstanceHandle& handle)
{
    DDS::ReturnCode_t result = ((dds::domain::DomainParticipant)dp)->dp_->ignore_topic(handle->handle());
    org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::ignore_topic"));
}

template <typename FwdIterator>
void ignore(const dds::domain::DomainParticipant& dp, FwdIterator begin, FwdIterator end)
{
    for(FwdIterator i = begin; i < end; i++)
    {
      DDS::ReturnCode_t result = ((dds::domain::DomainParticipant)dp)->dp_->ignore_topic(i->handle());
      org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::ignore_topic"));
    }
}

}}

// End of implementation

#endif /* OSPL_DDS_TOPIC_DISCOVERY_HPP_ */
