#pragma once

#include <list>
#include <functional>

namespace dekq
{
	namespace formal
	{
		namespace events
		{
			template <typename EventParameter>
			class Event
			{
			public:
				//Subscribe to event
				typename std::list< std::function<void(EventParameter)> >::iterator operator+=(std::function<void(EventParameter)> listener);
				//Unsubscribe to event
				void operator-=(typename std::list< std::function<void(EventParameter)> >::iterator position);
				
				void raise(EventParameter parameters);

			private:
				std::list<std::function<void(EventParameter)> > listeners;
			};

			template<typename EventParameter>
			inline typename std::list<std::function<void(EventParameter)>>::iterator Event<EventParameter>::operator+=(std::function<void(EventParameter)> listener)
			{
				listeners.push_back(listener);
				return --listeners.end();
			}
			template<typename EventParameter>
			inline void Event<EventParameter>::operator-=(typename std::list<std::function<void(EventParameter)>>::iterator position)
			{
				listeners.erase(position);
			}
			template<typename EventParameter>
			inline void Event<EventParameter>::raise(EventParameter parameters)
			{
				for (auto it : listeners)
				{
					it(parameters);
				}
			}
		}
	}
}