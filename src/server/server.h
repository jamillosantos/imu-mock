/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#ifndef VISUALIZER_SERVER_H
#define VISUALIZER_SERVER_H

#include <iostream>

#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <thread>

#include "../data/imu.h"
#include "../definitions.h"

namespace server
{
using namespace boost::asio::ip;

class Server
{
private:
	std::unique_ptr<std::thread> _thread;

	boost::asio::io_service ioService;
	udp::socket _socket;
	udp::endpoint sender_endpoint;

	data::Imu &imu;

	enum
	{
		max_length = 1024
	};
	char _data[max_length];

	void receive();

protected:
	virtual void process(std::string data);

public:
	Server(short port, data::Imu &imu);

	void runIoServiceTrampolin();

	void send(std::size_t length);

	void start();
};

}


#endif //VISUALIZER_SERVER_H
