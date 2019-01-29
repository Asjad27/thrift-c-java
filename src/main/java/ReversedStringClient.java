import org.apache.thrift.TException;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransport;

public class ReversedStringClient {
    final static String stringToReverse = "Hello world";
    public static void main(String [] args) {
        try {
            TTransport transport;
            transport = new TSocket("localhost", 9090);
            transport.open();
            TProtocol protocol = new  TBinaryProtocol(transport);
            ReverseStringService.Client client = new ReverseStringService.Client(protocol);
            perform(client, stringToReverse);
            transport.close();
        } catch (TException x) {
            x.printStackTrace();
        }
    }

    private static void perform(ReverseStringService.Client client, String stringToReverse) throws TException
    {
        System.out.println("String to reverse: " + stringToReverse);
        String reversed = client.reverseString(stringToReverse);
        System.out.println("Reversed string: " + reversed);
    }
}