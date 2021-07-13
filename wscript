# -*- Mode: python; py-indent-offset: 4; indent-tabs-mode: nil; coding: utf-8; -*-

def build(bld):
    module = bld.create_ns3_module('icar', ['internet', 'mobility'])
    module.includes = '.'
    module.source = [
        'model/icar.cc',
        'model/icar-header.cc',
        'helper/icar-helper.cc',
        'model/digitalMap.cc',
        ]

    module_test = bld.create_ns3_module_test_library('icar')
    module_test.source = [
        'test/icar-test-suite.cc',
        ]

    headers = bld(features='ns3header')
    headers.module = 'icar'
    headers.source = [
        'model/icar.h',
        'model/icar-header.h',
        'helper/icar-helper.h',
        'model/digitalMap.h',
        ]

    if bld.env.ENABLE_EXAMPLES:
        bld.recurse('examples')

    bld.ns3_python_bindings()