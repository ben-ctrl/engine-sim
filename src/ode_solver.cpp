#include "../include/ode_solver.h"

OdeSolver::OdeSolver() {
    /* void */
}

OdeSolver::~OdeSolver() {
    /* void */
}

void OdeSolver::initializeSystem(
        System *target,
        int bodyCount,
        double dt)
{
    if (target->BodyCount != bodyCount) {
        target->AngularAcceleration = new double[bodyCount];
        target->AngularVelocity = new double[bodyCount];
        target->Angles = new double[bodyCount];

        target->Acceleration_X = new double[bodyCount];
        target->Acceleration_Y = new double[bodyCount];
        target->Velocity_X = new double[bodyCount];
        target->Velocity_Y = new double[bodyCount];
        target->Position_X = new double[bodyCount];
        target->Position_Y = new double[bodyCount];

        target->Force_X = new double[bodyCount];
        target->Force_Y = new double[bodyCount];
        target->Torque = new double[bodyCount];

        target->BodyCount = bodyCount;
    }

    target->dt = dt;
}

void OdeSolver::copySystem(System *source, System *target) {
    initializeSystem(target, source->BodyCount, source->dt);

    for (int i = 0; i < source->BodyCount; ++i) {
        target->Acceleration_X[i] = source->Acceleration_X[i];
        target->Acceleration_Y[i] = source->Acceleration_Y[i];
        target->AngularAcceleration[i] = source->AngularAcceleration[i];

        target->Angles[i] = source->Angles[i];
        target->AngularVelocity[i] = source->AngularVelocity[i];

        target->Velocity_X[i] = source->Velocity_X[i];
        target->Velocity_Y[i] = source->Velocity_Y[i];
        target->Position_X[i] = source->Position_X[i];
        target->Position_Y[i] = source->Position_Y[i];

        target->Force_X[i] = source->Force_X[i];
        target->Force_Y[i] = source->Force_Y[i];
        target->Torque[i] = source->Torque[i];
    }
}

void OdeSolver::destroySystem(System *target) {
    if (target->Acceleration_X == nullptr) return;

    delete[] target->AngularAcceleration;
    delete[] target->AngularVelocity;
    delete[] target->Angles;

    delete[] target->Acceleration_X;
    delete[] target->Acceleration_Y;
    delete[] target->Velocity_X;
    delete[] target->Velocity_Y;
    delete[] target->Position_X;
    delete[] target->Position_Y;

    delete[] target->Force_X;
    delete[] target->Force_Y;
    delete[] target->Torque;

    target->Acceleration_X = nullptr;
    target->Acceleration_Y = nullptr;
    target->AngularAcceleration = nullptr;
    target->Angles = nullptr;

    target->Velocity_X = nullptr;
    target->Velocity_Y = nullptr;
    target->Position_X = nullptr;
    target->Position_Y = nullptr;

    target->Force_X = nullptr;
    target->Force_Y = nullptr;
    target->Torque = nullptr;

    target->BodyCount = 0;
}

void OdeSolver::start(System *initial, double dt) {
    m_dt = dt;
    m_bodyCount = initial->BodyCount;
}

bool OdeSolver::step(System *system) {
    return true;
}

void OdeSolver::solve(System *in, System *out) {
    /* void */
}

void OdeSolver::end() {
    /* void */
}