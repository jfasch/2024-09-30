#!/usr/bin/env python

from configparser import ConfigParser
import sys


infile = sys.argv[1]
outfile = sys.argv[2]


config = ConfigParser()
config.read(infile)

sensor = sink = None

for name, section in config.items():
    if name == 'DEFAULT':
        continue
    if name == 'Sensor':
        if sensor is not None:
            print('duplicate sensor section', file=sys.stderr)
            sys.exit(1)

        ty = section.get('type')
        if ty is None:
            print(f'section "{name}" has no "Type" attribute', file=sys.stderr)
            sys.exit(1)
        if ty == 'File':
            path = section.get('path')
            if path is None:
                print(f'section "{name}" has no "Type" attribute', file=sys.stderr)
                sys.exit(1)
            sensor = ('base/file-sensor.h', 'dts::FileSensor', (f'"{path}"',))
            continue

        print(f'section "{name}": unknown "Type" attribute "{ty}"', file=sys.stderr)
        sys.exit(1)

    if name == 'Sink':
        ty = section.get('type')
        if ty is None:
            print(f'section "{name}" has no "Type" attribute', file=sys.stderr)
            sys.exit(1)
        if ty == 'stdout':
            sink = ('base/CoutSink.h', 'dts::CoutSink', ())
            continue
        if ty == 'csv':
            path = section.get('path')
            if path is None:
                print(f'section "{name}" has no "Path" attribute', file=sys.stderr)
                sys.exit(1)
            sink = ('base/CsvSink.h', 'dts::CsvSink', (f'"{path}"',))
            continue

        print(f'section "{name}": unknown "Type" attribute "{ty}"', file=sys.stderr)
        sys.exit(1)

    print(f'unknown section "{name}"', file=sys.stderr)
    sys.exit(1)

    
lines = []

sensor_inc, sensor_type, sensor_params = sensor
sink_inc, sink_type, sink_params = sink

lines.append(f'#include <{sensor_inc}>')
lines.append(f'#include <{sink_inc}>')
lines.append('')
lines.append(f'static {sensor_type} _sensor({','.join(sensor_params)});')
lines.append(f'static {sink_type} _sink({','.join(sink_params)});')
lines.append('')
lines.append('dts::ISensor& the_sensor = _sensor;')
lines.append('dts::IDataSink& the_sink = _sink;')

with open(outfile, 'w') as f:
    f.write('\n'.join(lines))
