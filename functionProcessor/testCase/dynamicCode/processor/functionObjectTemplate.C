/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "functionObjectTemplate.H"
#include "fvCFD.H"
#include "unitConversion.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(processorFunctionObject, 0);

addRemovableToRunTimeSelectionTable
(
    functionObject,
    processorFunctionObject,
    dictionary
);


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    // dynamicCode:
    // SHA1 = fa6bcb9352550c3007ffd513d48777a6a88042f2
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void processor_fa6bcb9352550c3007ffd513d48777a6a88042f2(bool load)
    {
        if (load)
        {
            // code that can be explicitly executed after loading
        }
        else
        {
            // code that can be explicitly executed before unloading
        }
    }
}


// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

const fvMesh& processorFunctionObject::mesh() const
{
    return refCast<const fvMesh>(obr_);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

processorFunctionObject::processorFunctionObject
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    functionObjects::regionFunctionObject(name, runTime, dict)
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

processorFunctionObject::~processorFunctionObject()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool processorFunctionObject::read(const dictionary& dict)
{
    if (false)
    {
        Info<<"read processor sha1: fa6bcb9352550c3007ffd513d48777a6a88042f2\n";
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool processorFunctionObject::execute()
{
    if (false)
    {
        Info<<"execute processor sha1: fa6bcb9352550c3007ffd513d48777a6a88042f2\n";
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool processorFunctionObject::write()
{
    if (false)
    {
        Info<<"write processor sha1: fa6bcb9352550c3007ffd513d48777a6a88042f2\n";
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool processorFunctionObject::end()
{
    if (false)
    {
        Info<<"end processor sha1: fa6bcb9352550c3007ffd513d48777a6a88042f2\n";
    }

//{{{ begin code
    #line 62 "/home/inabower/OpenFOAM_TF/OpenFOAM4.1-utilities/functionProcessor/testCase/system/controlDict.functions.processor"
Info << "coded Function Start" << endl;

            volScalarField& dist = const_cast<volScalarField&>
            (mesh().lookupObject<volScalarField>("cellDist"));

            forAll(dist, i)
            {
                const vector& C = mesh().C()[i];
                const scalar& x = C[0];
                const scalar& y = C[1];
                const scalar& z = C[2];

                scalar& d = dist[i];
                const scalar r = 0.0254;
                const scalar RR = 0.1;

                d = 4;
                if(x<0.3)
                {
                  d=0;
                }
                else if(x<0.5)
                {
                  if(Foam::sqr(y)+Foam::sqr(z)<Foam::sqr(0.02))
                  {
                    d=1;
                  }
                  else
                  {
                    d=2;
                  }
                }
                else if(z<0.1)
                {
                  if
                  ( // equation of torus
                    Foam::sqr
                    (
                      Foam::sqrt(
                        Foam::sqr(x-0.5)+Foam::sqr(z-0.1)
                      ) - RR
                    )
                    + Foam::sqr(y) < Foam::sqr(0.02)
                  ) {
                    d = 1;
                  }
                  else
                  {
                    d = 2;
                  }
                }
                else if(z < 0.2)
                {
                  if(Foam::sqr(x-0.6)+Foam::sqr(y)<Foam::sqr(0.02))
                  {
                    d=1;
                  }
                  else
                  {
                    d=2;
                  }
                }
                else if(x<0.7)
                {
                  if
                  ( // equation of torus
                    Foam::sqr
                    (
                      Foam::sqrt(
                        Foam::sqr(x-0.7)+Foam::sqr(z-0.2)
                      ) - RR
                    )
                    + Foam::sqr(y) < Foam::sqr(0.02)
                  ) {
                    d = 1;
                  }
                  else
                  {
                    d = 2;
                  }
                }
                else
                {
                  d = 3;
                }
            }
//}}} end code

    return true;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

