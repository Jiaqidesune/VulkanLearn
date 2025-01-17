#include "ImageView.h"
#include "Image.h"
#include "Device.h"

#include <stdexcept>

namespace Rendering
{
	ImageView::ImageView(const Application& app, const Image& image, VkImageAspectFlags aspectFlags) : Object(app)
	{
		VkImageViewCreateInfo imageViewCreateInfo{};
		imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		imageViewCreateInfo.image = image.getHandle();
		imageViewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
		imageViewCreateInfo.format = image.getFormat();
		imageViewCreateInfo.subresourceRange.aspectMask = aspectFlags;
		imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
		imageViewCreateInfo.subresourceRange.levelCount = 1;
		imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
		imageViewCreateInfo.subresourceRange.layerCount = 1;

		if (vkCreateImageView(getDevice().getHandle(), &imageViewCreateInfo, nullptr, &m_handle.get()) != VK_SUCCESS)
			throw std::runtime_error("failed to create texture image view!");
	}

	ImageView::~ImageView()
	{
		vkDestroyImageView(getDevice().getHandle(), m_handle, nullptr);
	}
}