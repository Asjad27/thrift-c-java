namespace cpp thrift
namespace java thrift

service ReverseStringService
{
    string reverseString(1:string stringToReverse)
}