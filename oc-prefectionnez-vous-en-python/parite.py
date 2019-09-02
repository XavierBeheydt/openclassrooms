#!/usr/bin/env python3
# coding: utf-8

# Import without make module as lib
# import csv_analysis as c_an 
# import xml_analysis as x_an

# import as lib
import parser.csv as csv
omport parser.xml as xml

if __name__ == "__main__":
    c_an.launch_analysis('current_mps.csv')
    x_an.launch_analysis('SyceronBrut.xml')
