﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/iam/model/ListOrganizationsFeaturesResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <utility>

using namespace Aws::IAM::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils::Logging;
using namespace Aws::Utils;
using namespace Aws;

ListOrganizationsFeaturesResult::ListOrganizationsFeaturesResult()
{
}

ListOrganizationsFeaturesResult::ListOrganizationsFeaturesResult(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

ListOrganizationsFeaturesResult& ListOrganizationsFeaturesResult::operator =(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (!rootNode.IsNull() && (rootNode.GetName() != "ListOrganizationsFeaturesResult"))
  {
    resultNode = rootNode.FirstChild("ListOrganizationsFeaturesResult");
  }

  if(!resultNode.IsNull())
  {
    XmlNode organizationIdNode = resultNode.FirstChild("OrganizationId");
    if(!organizationIdNode.IsNull())
    {
      m_organizationId = Aws::Utils::Xml::DecodeEscapedXmlText(organizationIdNode.GetText());
    }
    XmlNode enabledFeaturesNode = resultNode.FirstChild("EnabledFeatures");
    if(!enabledFeaturesNode.IsNull())
    {
      XmlNode enabledFeaturesMember = enabledFeaturesNode.FirstChild("member");
      while(!enabledFeaturesMember.IsNull())
      {
        m_enabledFeatures.push_back(FeatureTypeMapper::GetFeatureTypeForName(StringUtils::Trim(enabledFeaturesMember.GetText().c_str())));
        enabledFeaturesMember = enabledFeaturesMember.NextNode("member");
      }

    }
  }

  if (!rootNode.IsNull()) {
    XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
    m_responseMetadata = responseMetadataNode;
    AWS_LOGSTREAM_DEBUG("Aws::IAM::Model::ListOrganizationsFeaturesResult", "x-amzn-request-id: " << m_responseMetadata.GetRequestId() );
  }
  return *this;
}
