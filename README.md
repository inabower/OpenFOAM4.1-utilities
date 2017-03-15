They are utilities of OpenFOAM 4.1 for myself.

### faceDirection

To post-process the direction of patches.
After exection, you can get the volVectorField.
And then you can show the direction in paraview.

#### exemple
    > Checking after createBaffles if your mesh is created by other meshing software (i.e. SALOME)

### reverseSurface

To modify STL files.
- If you tipe `reverseSurface old.stl new.stl 0`, you can get STL which is changed its precision for OpenFOAM.
- If you enter `reverseSurface old.stl new.stl 1`, every face is fliped.

#### exemple
- Before using snappyHexMesh with your separated surface meshes made by interfaces of partition solid of SALOME.

### manualDecomposition
This is to decompose cells for parallel.
You can distribute cells to your processors as you want.

#### exemple
- Decreasing number of interface faces between processors
- Calculate one patch in same processor
- Devide cyclicAMI as you want
- Averaging the numbers of cells in one processor.

### functionProcessor
**manualDecomposition** without compiling at every time.
Read *functionProcessor/README.md*

