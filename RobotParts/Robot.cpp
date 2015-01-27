#include "Robot.h"


Robot::Robot(void)
{
	m_SelectedPart = Parts::Body;
	m_PreviousPart = Parts::None;
	m_NextPart = Parts::FirstJoint;

	m_pBody = new Body();
	m_pFirstJoint = new Joint();
	m_pFirstArm = new Arm();
	m_pSecondJoint = new Joint();
	m_pSecondArm = new Arm();
	m_pHand = new Hand();

    m_PositionX = 0;
    m_FirstArmHeight = 75;
    m_SecondArmHeight = 75;
    m_FirstJointAngle = 0;
    m_SecondJointAngle = 0;
    m_HandAngle = 0.0f;

    m_DoOpenHand = false;
}


Robot::~Robot(void)
{
}

void Robot::SelectPart(Parts part)
{
switch (part)
	{
	case Robot::Parts::None:
		m_SelectedPart = Parts::Body;
		break;
	case Robot::Parts::Body:
		{
			m_SelectedPart = Parts::Body;
			m_NextPart = Parts::FirstJoint;
			m_PreviousPart = Parts::None;
		}
		break;
	case Robot::Parts::FirstJoint:
		{
			m_PreviousPart = Parts::Body;
			m_SelectedPart = Parts::FirstJoint;
			m_NextPart = Parts::FirstArm;
		}
		break;
	case Robot::Parts::FirstArm:
		{
			m_PreviousPart = Parts::FirstJoint;
			m_SelectedPart = Parts::FirstArm;
			m_NextPart = Parts::SecondJoint;
		}
		break;
	case Robot::Parts::SecondJoint:
		{
			m_PreviousPart = Parts::FirstArm;
			m_SelectedPart = Parts::SecondJoint;
			m_NextPart = Parts::SecondArm;
		}
		break;
	case Robot::Parts::SecondArm:
		{
			m_PreviousPart = Parts::SecondJoint;
			m_SelectedPart = Parts::SecondArm;
			m_NextPart = Parts::Hand;
		}
		break;
	case Robot::Parts::Hand:
		{
			m_PreviousPart = Parts::SecondArm;
			m_SelectedPart = Parts::Hand;
			m_NextPart = Parts::Hand;
		}
		break;
	default:
		break;
	}
}

void Robot::m_Draw()
{
    // Body
    //
    if(m_SelectedPart == Parts::Body)
        glColor3f(0, 1, 0);
    glTranslatef(m_PositionX, 0, 0);
    m_pBody->createBody(50);
    glColor3f(1, 1, 1);

    // FirstJoint
    //
    if(m_SelectedPart == Parts::FirstJoint)
        glColor3f(0, 1, 0);
    glTranslatef(25.0f, -75.0f, 0.0f);
    glRotatef(m_FirstJointAngle, 0, 0, 1);
    m_pFirstJoint->createJoint(25);
    glColor3f(1, 1, 1);

    // FirsArm
    //
    if(m_SelectedPart == Parts::FirstArm)
        glColor3f(0, 1, 0);
    glTranslatef(-10.0f, -25.0f, 0.0f);
    //glRotatef(180, 0, 0, 1);
    m_pFirstArm->createArm(20, m_FirstArmHeight);
    glColor3f(1, 1, 1);

    // SecondJoint
    //
    if(m_SelectedPart==Parts::SecondJoint)
        glColor3f(0, 1, 0);
    glTranslatef(10.0f, -(m_FirstArmHeight + 15.0f), 0.0f);
    glRotatef(m_SecondJointAngle, 0, 0, 1);
    m_pSecondJoint->createJoint(15);
    glColor3f(1, 1, 1);

    // SecondArm
    //
    if(m_SelectedPart == Parts::SecondArm)
        glColor3f(0, 1, 0);
   glTranslatef(-5.0f, -15.0f, 0.0f);
   //glRotatef(180, 0, 0, 1);
    m_pSecondArm->createArm(10, m_SecondArmHeight);
    glColor3f(1, 1, 1);
     
    // Hand
    //
    if(m_SelectedPart == Parts::Hand)
        glColor3f(0, 1, 0);
    if(m_DoOpenHand)
        OpenHand();
    else
        CloseHand();
    glTranslatef(5.0f, -(m_SecondArmHeight + 10.0f), 0.0f);
    m_pHand->createHand(10, 30, m_HandAngle);

    glColor3f(1, 1, 1);
}

void Robot::MoveRobot(int value)
{
    switch (m_SelectedPart)
    {
    case Robot::Parts::None:
        break;
    case Robot::Parts::Body:
        m_PositionX -= value;
        break;
    case Robot::Parts::FirstJoint:
        if(m_FirstJointAngle > -90 && m_FirstJointAngle < 90)
        {
            m_FirstJointAngle -= value;
            if(m_FirstJointAngle <= -90.0f)
                m_FirstJointAngle = -89.9f;
            if(m_FirstJointAngle >= 90.0f)
                m_FirstJointAngle = 89.9f;
        }
        break;
    case Robot::Parts::FirstArm:
        if(m_FirstArmHeight > 0 && m_FirstArmHeight < 150)
        {
            m_FirstArmHeight -= value;
            if(m_FirstArmHeight <= 0)
                m_FirstArmHeight = 1;
            if(m_FirstArmHeight >= 150)
                m_FirstArmHeight = 149;
        }
        break;
    case Robot::Parts::SecondJoint:
        if (m_SecondJointAngle > -90.0f && m_SecondJointAngle < 90.0f)
        {
            m_SecondJointAngle -= value;
            if(m_SecondJointAngle <= -90.0f)
                m_SecondJointAngle = 89.9f;
            if(m_SecondJointAngle >= 90.0f)
                m_SecondJointAngle = 89.9f;
        }
        break;
    case Robot::Parts::SecondArm:
        if (m_SecondArmHeight > 0 && m_SecondArmHeight < 150)
        {
            m_SecondArmHeight -= value;
            if(m_SecondArmHeight <= 0)
                m_SecondArmHeight = 1;
            if(m_SecondArmHeight >= 150)
                m_SecondArmHeight = 149;
        }
        break;
    case Robot::Parts::Hand:
        m_DoOpenHand = true;
        break;
    default:
        break;
    }
}

void Robot::OpenHand()
{
    if(m_HandAngle < 30.0f)
    {
        m_HandAngle += 1.0f;
        if(m_HandAngle >= 30.0f)
        {
            m_DoOpenHand = false;
            m_HandAngle = 30.0f;
        }
    }
}

void Robot::CloseHand()
{
    if(m_HandAngle > 0.0f)
    {
        m_HandAngle -= 1.0f;
        if(m_HandAngle <= 0.0f)
        {
            m_HandAngle == 0.0f;
        }
    }
}