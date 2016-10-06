/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "server.h"

server::Server::Server(short port, data::Imu &imu)
	: _socket(ioService, udp::endpoint(udp::v4(), port)), imu(imu)
{}

void server::Server::send(std::size_t length)
{
	this->_socket.async_send_to(
		boost::asio::buffer(_data, length), sender_endpoint,
		[this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
		{
			receive();
		});
}

void server::Server::receive()
{
	this->_socket.async_receive_from(
		boost::asio::buffer(_data, max_length), sender_endpoint,
		[this](boost::system::error_code ec, std::size_t bytes_recvd)
		{
			if (!ec && bytes_recvd > 0)
			{
				receive();
				process(std::string(_data, bytes_recvd));
			}
			else
				receive();
		});
}

void server::Server::process(std::string data)
{
	// VERBOSE(data);
	std::vector<std::string> strs;
	boost::split(strs, data, boost::is_any_of(" "));
	if (strs.size() == 10)
	{
		try
		{
			this->imu.accelerometer.xyz(
				boost::lexical_cast<double>(strs[1]),
				boost::lexical_cast<double>(strs[2]),
				boost::lexical_cast<double>(strs[3])
			);
			this->imu.gyro.xyz(
				boost::lexical_cast<double>(strs[4]),
				boost::lexical_cast<double>(strs[5]),
				boost::lexical_cast<double>(strs[6])
			);
			this->imu.magnetometer.xyz(
				boost::lexical_cast<double>(strs[7]),
				boost::lexical_cast<double>(strs[8]),
				boost::lexical_cast<double>(strs[9])
			);
			this->imu.broadcastUpdate();
		}
		catch (boost::bad_lexical_cast &e)
		{
			ERROR(e.what());
		}
	}
	else
	{
		ERROR("Size of data mismatch!");
	}
}

void server::Server::start()
{
	if (!this->_thread)
	{
		this->_thread.reset(new std::thread(&server::Server::runIoServiceTrampolin, this));
	}
}

void server::Server::runIoServiceTrampolin()
{
	this->receive();
	this->ioService.run();
}
