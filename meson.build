project('nitfol', 'c', version : '0.5')

# zlib_dep = dependency('zlib')

bison_exe = find_program('bison')
bison = generator(bison_exe,
                  output : '@PLAINNAME@.c',
                  arguments : ['-y', '-o', '@OUTPUT@', '@INPUT@'])

os_name = 'unix'
perl_exe = find_program('perl')
startc = custom_target('start' + os_name + '.c',
                       input : ['opt2glkc.pl', 'nitfol.opt'],
                       output : 'start' + os_name + '.c',
                       command : [perl_exe, '@INPUT0@', '-' + os_name, '@INPUT1@'])
dbg_help = custom_target('dbg_help',
                         input : ['y2help.pl', 'inform.y'],
                         output : ['dbg_help.h', 'dbg_help.texi'],
                         command : [perl_exe, '@INPUT0@', '@INPUT1@'])

# gawk_exe = find_program('gawk')
# gawk = generator(gawk)

if get_option('glk_backend') == 'glkterm'
    glk_dep = dependency('glkterm', static : true)
    glk_srcs = ['no_graph.c', 'blorb.c', 'no_snd.c']
elif get_option('glk_backend') == 'glktermw'
    glk_dep = dependency('glktermw', static : true)
    glk_srcs = ['no_graph.c', 'blorb.c', 'no_snd.c']
else
    error('Glk backend not specified via \'glk_backend\' option')
endif

bison_srcs = bison.process('inform.y')

nitfol_srcs = [
    'automap.c',
    'solve.c',
    'infix.c',
    'copying.c',
    'debug.c',
    'quetzal.c',
    'undo.c',
    'op_call.c',
    'decode.c',
    'errmesg.c',
    'globals.c',
    'iff.c',
    'init.c',
    'main.c',
    'io.c',
    'z_io.c',
    'op_jmp.c',
    'op_math.c',
    'op_save.c',
    'op_table.c',
    'op_v6.c',
    'oplist.c',
    'stack.c',
    'zscii.c',
    'tokenise.c',
    'struct.c',
    'objects.c',
    'portfunc.c',
    'hash.c',
    glk_srcs,
    bison_srcs,
    dbg_help,
    startc
]

executable('nitfol', sources : nitfol_srcs, dependencies : glk_dep, c_args : ['-ansi','-DSMART_TOKENISER', '-DNO_TICK', '-DDEBUGGING'], install : true)
 
