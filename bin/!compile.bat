@echo off

if "%1" == "" goto fail

csg %1
bsp %1
vis %1
light %1
alpha2goldsrc %1
