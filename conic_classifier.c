#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **allocate_matrix() {
    int i;
    double **m;
    
    m = (double **)malloc(3 * sizeof(double *));
    for (i = 0; i < 3; i++) {
        m[i] = (double *)calloc(3, sizeof(double));
    }

    return m;
}

void deallocate_matrix(double **m) {
    int i;

    for (i = 0; i < 3; i++) {
        free(m[i]);
    }
    free(m);
}

void error(double r, int *op) {
    printf("%0.lf is not a valid root, please enter again.\n", r);
    *op = 0;
}

void writing_equation(double *a, double *b, double *c, double *d, double *e, double *f) {
    double r;
    int op = 0;

    printf("If any coefficient has a root, enter the number without root and its root separated by a space (' ').\n");
    printf("Example: if the value is 10*sqrt(2), enter '10 2'\n\n");
    printf("If it's without root, enter the number and '1' separated by space (' ')\n");
    printf("Example: if the value is 10, enter '10 1'\n\n");

    printf("Enter the value of 'a':");
    while (!op) {
        scanf("%lf %lf", &*a, &r);
        if (r < 0) error(r, &op);
        else op = 1;
    }
    *a = *a * sqrt(r);
    op = 0;

    printf("Enter the value of 'b':");
    while (!op) {
        scanf("%lf %lf", &*b, &r);
        if (r < 0) error(r, &op);
        else op = 1;
    }
    *b = *b * sqrt(r);
    op = 0;

    printf("Enter the value of 'c':");
    while (!op) {
        scanf("%lf %lf", &*c, &r);
        if (r < 0) error(r, &op);
        else op = 1;
    }
    *c = *c * sqrt(r);
    op = 0;

    printf("Enter the value of 'd':");
    while (!op) {
        scanf("%lf %lf", &*d, &r);
        if (r < 0) error(r, &op);
        else op = 1;
    }
    *d = *d * sqrt(r);
    op = 0;

    printf("Enter the value of 'e':");
    while (!op) {
        scanf("%lf %lf", &*e, &r);
        if (r < 0) error(r, &op);
        else op = 1;
    }
    *e = *e * sqrt(r);
    op = 0;

    printf("Enter the value of 'f':");
    while (!op) {
        scanf("%lf %lf", &*f, &r);
        if (r < 0) error(r, &op);
        else op = 1;
    }
    *f = *f * sqrt(r);

    printf("\nThe equation is:\n");
    printf("(%0.2lf)x² + (%0.2lf)xy + (%0.2lf)y² + (%0.2lf)x + (%0.2lf)y + (%0.2lf) = 0\n", *a, *b, *c, *d, *e, *f);
    printf("Is the equation correct? If yes, press 1. If not, press 2.\n");
}

void translation(double **m, double a, double b, double c, double d, double e, double f, double *F) {
    double h, k;

    printf("our system is:\n");
    printf("(%0.2lf)h + (%0.2lf)k + (%0.2lf) = 0\n", m[0][0], m[0][1], m[0][2]);
    printf("(%0.2lf)h + (%0.2lf)k + (%0.2lf) = 0\n\n", m[0][1], m[1][1], m[1][2]);

    k = ((d * b) - (2 * a * e)) / ((4 * a * c) - (b * b));
    h = (-(b * k) - d) / (2 * a);

    printf("h is %0.2lf and k is %0.2lf\n", h, k);
    printf("The center of the conic is: (%0.2lf, %0.2lf)\n\n", h, k);

    *F = (d * h) / 2 + (e * k) / 2 + f;

    printf("The equation is now in this form:\n");

    if (b == 0) {
        printf("(%0.2lf)u² + (%0.2lf)v² + (%0.2lf) = 0\n\n", a, c, *F);
    } else {
        printf("(%0.2lf)u² + (%0.2lf)uv + (%0.2lf)v² + (%0.2lf) = 0\n\n", a, b, c, *F);
    }
}

void calculating_ellipse(double a, double b) {
    double c, exc, cent;

    a = sqrt(pow(a, -1));
    b = sqrt(pow(b, -1));

    if (a > b) {
        c = sqrt((a * a) - (b * b));
        exc = c / a;
        cent = b / a;

        printf("The major axis measures (%0.2lf)\n", 2 * a);
        printf("The minor axis measures (%0.2lf)\n", 2 * b);
        printf("The focal distance measures (%0.2lf)\n", 2 * c);
        printf("The coordinates of the foci are (%0.2lf, 0) and (%0.2lf, 0)\n", -c, c);
        printf("The eccentricity of the ellipse is (%0.2lf)\n", exc);
        printf("The centrality of the ellipse is (%0.2lf)\n", cent);
    } else if (a < b) {
        c = sqrt((b * b) - (a * a));
        exc = c / b;
        cent = a / b;

        printf("The major axis measures (%0.2lf)\n", 2 * b);
        printf("The minor axis measures (%0.2lf)\n", 2 * a);
        printf("The focal distance measures (%0.2lf)\n", 2 * c);
        printf("The coordinates of the foci are (0, %0.2lf) and (0, %0.2lf)\n", c, -c);
        printf("The eccentricity of the ellipse is (%0.2lf)\n", exc);
        printf("The centrality of the ellipse is (%0.2lf)\n", cent);
    }
}

void calculating_hyperbola(double a, double b) {
    double c, assint, exc;

    if (a < 0) {
        a = -a;
        a = -sqrt(pow(a, -1));
    } else {
        a = sqrt(pow(a, -1));
    }
    if (b < 0) {
        b = -b;
        b = -sqrt(pow(b, -1));
    } else {
        b = sqrt(pow(b, -1));
    }

    c = sqrt((a * a) + (b * b));

    if (a > b) {
        exc = c / a;
        assint = a / b;

        printf("The vertex coordinates are (%0.2lf, 0) and (%0.2lf, 0)\n", -a, a);
        printf("The focal coordinates are (%0.2lf, 0) and (%0.2lf, 0)\n", -c, c);
        printf("The equations of the asymptotes are y=%0.2lfx and y=%0.2lfx\n", -assint, assint);
        printf("The eccentricity of the hyperbola is (%0.2lf)\n", exc);
    } else if (a < b) {
        exc = c / b;
        assint = b / a;

        printf("The vertex coordinates are (%0.2lf, 0) and (%0.2lf, 0)\n", -b, b);
        printf("The focal coordinates are (0, %0.2lf) and (0, %0.2lf)\n", c, -c);
        printf("The equations of the asymptotes are y=%0.2lfx and y=%0.2lfx\n", -assint, assint);
        printf("The eccentricity of the hyperbola is (%0.2lf)\n", exc);
    }
}

void calculating_parabola(double a, double A, double C) {
    double p;

    p = a / 4;

    if (A == 0) {
        printf("The focus coordinates are (%0.2lf, 0)\n", p);
        printf("The directrix is x=%0.2lf\n", -p);
    } else if (C == 0) {
        printf("The focus coordinates are (0, %0.2lf)\n", p);
        printf("The directrix is y=%0.2lf\n", -p);
    }
    printf("The eccentricity of this and all parabolas is 1\n");
}

int main(int argc, char *argv[]) {
    double a, b, c, d, e, f, A, C, D, E, F, sen, cos, sen_2, det = 0, **matrix;
    int op = 0;

    matrix = allocate_matrix();

    do {
        writing_equation(&a, &b, &c, &d, &e, &f);
        scanf("%d", &op);
        while (op != 1 && op != 2) {
            printf("This option is not valid, please enter again.\n");
            scanf("%d", &op);
        }
        printf("\n");
    } while (op != 1);

    matrix[0][0] = a;
    matrix[0][1] = b / 2;
    matrix[0][2] = d / 2;
    matrix[1][0] = b / 2;
    matrix[1][1] = c;
    matrix[1][2] = e / 2;
    matrix[2][0] = d / 2;
    matrix[2][1] = e / 2;
    matrix[2][2] = f;

    printf("The symmetric matrix is:\n");
    printf("(%0.2lf\t%0.2lf\t%0.2lf)\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("(%0.2lf\t%0.2lf\t%0.2lf)\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("(%0.2lf\t%0.2lf\t%0.2lf)\n\n", matrix[2][0], matrix[2][1], matrix[2][2]);

    det = (matrix[0][0] * matrix[1][1]) - pow(matrix[0][1], 2);

    if (d == 0 && e == 0) {
        printf("Since this equation has no linear terms, we can skip the translation process.\n\n");
        F = f;
    } else {
        if (det != 0) {
            translation(matrix, a, b, c, d, e, f, &F);
        }
    }

    if (b == 0) {
        A = a;
        C = c;
    } else {
        C = (b * sqrt(1 + pow(((a - c) / b), 2)) - a - c) / -2;
        A = a + c - C;
        printf("The value of A is %0.2lf and the value of C is %0.2lf\n\n", A, C);
    }

    if (b == 0) {
        sen = 0;
        cos = 1;
    } else {
        sen_2 = 1 / sqrt(1 + pow((a - c) / b, 2));
        sen = sqrt((((a - c) * sen_2) - b) / (-2 * b));
        cos = sqrt(1 - pow(sen, 2));
    }

    if (det == 0) {
        printf("The value of '(a-c)-(b²/4)' is 0\n\n");

        F = f;

        if (d != 0 || e != 0) {
            D = (d * cos) + (e * sen);
            E = (d * -sen) + (e * cos);

            printf("The equation is now as follows:\n");

            if (A == 0) {
                if (F == 0) {
                    if (E == 0) {
                        printf("(%0.2lf)v² + (%0.2lf)u = 0\n\n", C, D);
                    } else {
                        printf("(%0.2lf)v² + (%0.2lf)u + (%0.2lf)v = 0\n\n", C, D, E);
                    }
                } else {
                    if (E == 0) {
                        printf("(%0.2lf)v² + (%0.2lf)u + (%0.2lf) = 0\n\n", C, D, F);
                    } else {
                        printf("(%0.2lf)v² + (%0.2lf)u + (%0.2lf)v + (%0.2lf) = 0\n\n", C, D, E, F);
                    }
                }

                D = -D / C;
                C = 1;

                printf("The reduced equation is:\n");
                printf("w² = (%0.2lf)t\n", D);
                printf("This equation represents a parabola\n\n");
                calculating_parabola(D, A, C);
            } else if (C == 0) {
                if (F == 0) {
                    if (D == 0) {
                        printf("(%0.2lf)u² + (%0.2lf)v = 0\n\n", A, E);
                    } else {
                        printf("(%0.2lf)u² + (%0.2lf)u + (%0.2lf)v = 0\n\n", A, D, E);
                    }
                } else {
                    if (D == 0) {
                        printf("(%0.2lf)u² + (%0.2lf)v + (%0.2lf) = 0\n\n", A, E, F);
                    } else {
                        printf("(%0.2lf)u² + (%0.2lf)u + (%0.2lf)v + (%0.2lf) = 0\n\n", A, D, E, F);
                    }
                }

                E = -E / A;
                A = 1;

                printf("The reduced equation is:\n");
                printf("t² = (%0.2lf)w\n", E);
                printf("This equation represents a parabola\n\n");
                calculating_parabola(E, A, C);
            }
        } else if (d == 0 && e == 0) {
            if (F == 0) {
                if (A == 0) {
                    printf("(%0.2lf)t² = 0\n", C);
                } else if (C == 0) {
                    printf("(%0.2lf)s² = 0\n", A);
                } else {
                    printf("(%0.2lf)s² + (%0.2lf)t² = 0\n", A, C);
                }
                printf("The equation represents two identical lines\n");
            } else if (F < 0) {
                if (A == 0) {
                    printf("(%0.2lf)t² = %0.2lf\n", C, -F);
                } else if (C == 0) {
                    printf("(%0.2lf)s² = %0.2lf\n", A, -F);
                } else {
                    printf("(%0.2lf)s² + (%0.2lf)t² = %0.2lf\n", A, C, -F);
                }
                printf("The equation represents two parallel lines\n");
            } else if (F > 0) {
                if (A == 0) {
                    printf("(%0.2lf)t² = %0.2lf\n", C, -F);
                } else if (C == 0) {
                    printf("(%0.2lf)s² = %0.2lf\n", A, -F);
                } else {
                    printf("(%0.2lf)s² + (%0.2lf)t² = %0.2lf\n", A, C, -F);
                }
                printf("The equation represents an empty set\n");
            }
        }
    } else {
        if (((A < 0 && C > 0) || (A > 0 && C < 0)) && F > 0) {
            A = -A;
            C = -C;
            F = -F;
        }

        if (F < 0) {
            if (A == C) {
                F = F / A;
                A = 1;
                C = 1;
                
                printf("The reduced equation is:\n");
                printf("(%0.2lf)s² + (%0.2lf)t² = (%0.2lf)\n", A, C, -F);
                printf("The equation represents a circle\n");
            } else if (A != C && A != 0 && C != 0) {
                A = A / -F;
                C = C / -F;
        
                printf("The reduced equation is:\n");
                printf("(%0.2lf)s² + (%0.2lf)t² = 1\n", A, C);
                if (A > 0 && C > 0) {
                    printf("This equation represents an ellipse\n\n");
                    calculating_ellipse(A, C);
                } else if ((A > 0 && C < 0) || (C > 0 && A < 0)) {
                    printf("This equation represents a hyperbola\n\n");
                    calculating_hyperbola(A, C);
                }
            }
        } else if (F == 0) {
            printf("The reduced equation is:\n");

            if (A > 0 && C > 0) {
                printf("(%0.2lf)s² + (%0.2lf)t² = 0\n", A, C);
                printf("The equation represents a point\n");
            } else if (A < 0 && C < 0) {
                printf("(%0.2lf)s² + (%0.2lf)t² = 0\n", -A, -C);
                printf("The equation represents a point\n");
            } else if ((A > 0 && C < 0) || (A < 0 && C > 0)) {
                printf("(%0.2lf)s² + (%0.2lf)t² = 0\n", A, C);
                printf("The equation represents two intersecting lines\n");
            }
        } else {
            printf("The reduced equation is:\n");
            printf("(%0.2lf)s² + (%0.2lf)t² = (%0.2lf)\n", A, C, -F);
            printf("The equation represents an empty set\n");
        }
    }

    deallocate_matrix(matrix);

    return 0;
}