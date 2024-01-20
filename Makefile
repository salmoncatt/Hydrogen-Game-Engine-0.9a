CC=gcc
LIBS  = -lglfw3dll -lopengl32 -lgdi32 -luser32 -lkernel32 -lfreetype -limagehlp -lwinmm
CFLAGS = -mavx -m64 -Isrc/HF -Iext/include -Iext/include/FreeType -Lext/lib
#TODO: (salmoncatt) dont make me write * for every new sub directory added
#SRC=$(wildcard src/*.c) $(wildcard src/*/*.c) $(wildcard src/*/*/*.c)

#only compile only windows main.c version in src folder
SRC= src/main.c $(wildcard src/*.c) $(wildcard src/*/*.c) $(wildcard src/*/*/*.c) $(wildcard src/*/*/*/*.c)
OBJS = $(SRC:.c=.o)


PCH_SRC = src/HF/hfpch.h
D_PCH_SRC = bin/dhfpch.h
PCH_OUT = src/HF/hfpch.h.gch
HF_RES = bin/hf_res.res
#PCH_OUT = bin/hfpch/hfpch.h.gch




main: $(SRC)
	 $(CC) -include $(PCH_SRC) -o bin\goober $^ $(CFLAGS) $(LIBS) $(HF_RES)









# compile precompiled header file here

#this pch has the HF_DEBUG removed
hfpch: $(D_PCH_SRC)
	$(CC) -c -o $(PCH_OUT) $< $(CFLAGS) $(LIBS)


#this removes the HF_DEBUG in hfpch
hfpch_remove_debug:
	grep -v '#define HF_DEBUG' $(PCH_SRC) > $(D_PCH_SRC)


#this leave HF_DEBUG in hfpch to enable debugging mode
hfpch_debug: $(PCH_SRC)
	$(CC) -c -o $(PCH_OUT) $< $(CFLAGS) $(LIBS) 
















#start /b /wait "" "cl" src\main.c /I..\ext\include /link opengl32.lib /libpath:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\um\x86" /out:goober.exe


