#pragma once

#include <vulkan/vulkan.h>

namespace Rendering
{
    class QueueFamily
    {
    public:
        QueueFamily(uint32_t index, VkQueueFamilyProperties properties);

        uint32_t getIndex() const { return m_index; }
        const VkQueueFamilyProperties& getProperties() const { return m_properties; }

    private:
        uint32_t m_index;
        VkQueueFamilyProperties m_properties;
    };
}