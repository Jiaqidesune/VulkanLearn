#pragma once

#include <vulkan/vulkan.h>
#include "VKGPUSyncRes.h"
#include <memory>
#include <vector>

namespace RHI
{
	class Device;

	class BufferBase : public VKGPUSyncRes
	{
	public:
		BufferBase(const std::shared_ptr<Device>& pDevice);
		virtual ~BufferBase() = default;

		// Getters
		VkPipelineStageFlags GetAccessStages() const { return m_accessStages; }
		VkAccessFlags GetAccessFlags() const { return m_accessFlags; }
		//virtual const VkBufferCreateInfo& GetBufferInfo() const = 0;

		virtual VkBuffer GetDeviceHandle() const = 0;

	protected:
		VkBufferCreateInfo m_info;
		VkPipelineStageFlags m_accessStages;
		VkAccessFlags m_accessFlags;
	};
}