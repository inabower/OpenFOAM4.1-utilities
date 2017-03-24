### residualSimpleFoam
This is a solver copied from simpleFoam.
It is modified to output the residuals as field.

#### residual fields
residual_p : initial residual of pEqn
residual_U : initial residual of UEqn

They are outputs of fvMatrix::residuals() which are calculated with log(mag()).

