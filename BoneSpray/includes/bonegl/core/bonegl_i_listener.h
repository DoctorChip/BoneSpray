#pragma once
namespace core
{
	class i_listener
	{
	public:
		virtual ~i_listener() = 0;

		virtual void notify_begin_frame() = 0;

		virtual void notify_display_frame() = 0;

		virtual void notify_end_frame() = 0;

		virtual void notify_reshape(int width, int height, int previous_width, int previous_height) = 0;
	};

	inline i_listener::~i_listener()
	{
	}
}