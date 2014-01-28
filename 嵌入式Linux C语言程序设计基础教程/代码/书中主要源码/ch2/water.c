#include <stdio.h>

int main(int argc,char **argv)
{
    float mass_mol = 3.0e-23;   
    float mass_qt = 950;        
    float quarts;
    float molecules;
    
    printf("mass_mol=%f %e\n", mass_mol, mass_mol);
    printf("Enter the number of quarts of water: ");
    scanf("%f", &quarts);
    molecules = quarts * mass_qt / mass_mol;
    printf("%f quarts of water contain %e(%f) molecules.\n", 
            quarts, molecules, molecules);

    return 0;
}
