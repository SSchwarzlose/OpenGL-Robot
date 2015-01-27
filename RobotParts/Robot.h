#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Arm.h"
#include "Body.hpp"
#include "Hand.h"
#include "Joint.h"
#include "Hand.h"

class Robot
{
public:
	Robot(void);
	~Robot(void);

	enum struct Parts
		{
			None,
			Body,
			FirstJoint,
			FirstArm,
			SecondJoint,
			SecondArm,
			Hand
		};

	Parts m_SelectedPart;
	Parts m_NextPart;
	Parts m_PreviousPart;

	void SelectPart(Parts part);
	void MoveRobot(int value);
    void m_Draw();

private:
    void OpenHand();
    void CloseHand();

	Body* m_pBody;
	Joint* m_pFirstJoint;
	Arm* m_pFirstArm;
	Joint* m_pSecondJoint;
	Arm* m_pSecondArm;
	Hand* m_pHand;

    int m_MoveValue;
    float m_PositionX;
    float m_FirstArmHeight;
    float m_FirstJointAngle;
    float m_SecondJointAngle;
    float m_SecondArmHeight;
    float m_HandAngle;

    bool m_DoOpenHand;
};

#endif