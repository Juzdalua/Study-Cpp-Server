
import argparse
import jinja2
import ProtoParser

'''
    1. Get .proto file
    2. Find message
    3. Get & Set messne name and id
'''
def main():    
    arg_parser = argparse.ArgumentParser(description = "PakcetGenerator")
    arg_parser.add_argument("--path", type=str, default="C:/Users/Jun/Desktop/workspace/study-cpp-server/Server/Common/Protobuf/bin/Protocol.proto", help="proto path")
    arg_parser.add_argument("--output", type=str, default="TestPacketHandler", help="output file")
    arg_parser.add_argument("--recv", type=str, default="C_", help="recv convention")
    arg_parser.add_argument("--send", type=str, default="S_", help="send convention")
    args = arg_parser.parse_args()
    
    parser = ProtoParser.ProtoParser(1000, args.recv, args.send)
    parser.parse_proto(args.path)
    
    # jinja2
    file_loader = jinja2.FileSystemLoader("Templates")
    env = jinja2.Environment(loader=file_loader)
    
    template = env.get_template("PacketHandler.h")
    output = template.render(parser = parser, output=args.output)
    
    f = open(args.output+'.h', 'w+')
    f.write(output)
    f.close()
    
    # check in cmd
    print(output)

    return

if __name__ == '__main__':
    main()