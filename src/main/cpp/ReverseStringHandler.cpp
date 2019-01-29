#include "../../../thrift/gen-cpp/ReverseStringService.h"
#include "../../../thrift/gen-cpp/ReverseStringService.cpp"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <string.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::thrift;

class ReverseStringServiceHandler : virtual public ReverseStringServiceIf {
 public:
  ReverseStringServiceHandler() { }

  void reverseString(std::string& _return, const std::string& stringToReverse) {
    char temp;
    std::string strToReverse = stringToReverse;
    int lengthOfString = strToReverse.size() - 1;
    for (int i = 0; i < lengthOfString; i++,lengthOfString--) {
        temp = strToReverse[i];
        strToReverse[i] = strToReverse[lengthOfString];
        strToReverse[lengthOfString] = temp;
    }
    _return = strToReverse;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<ReverseStringServiceHandler> handler(new ReverseStringServiceHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new ReverseStringServiceProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

