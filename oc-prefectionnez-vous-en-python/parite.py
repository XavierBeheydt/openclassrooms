#!/usr/bin/env python3
# coding: utf-8

# Import without make module as lib
# import csv_analysis as c_an 
# import xml_analysis as x_an

# import as lib
import parser.csv as csv
import parser.xml as xml

import argparse


def parser_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-e", "--extension", 
    help="""Type of file to analyse. It is a CSV or en XML?""")
    parser.add_argument("-d", "--datafile", 
    help="""CSV containing pieces of information""" 
    """about the members of parliament""")

    return parser.parse_args()


def main():
    args = parser_arguments()
    if args.extension == 'xml':
        xml.launch_analysis('SyceronBrut.xml')
    else:
        csv.launch_analysis('current_mps.csv')


if __name__ == "__main__":
    main()
