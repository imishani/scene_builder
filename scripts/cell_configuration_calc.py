# Copyright (C) 2023, Itamar Mishani
# All rights reserved.
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Carnegie Mellon University nor the names of its
#       contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

"""
* \file   cell_configuration_calc.py
* \author Itamar Mishani (imishani@cmu.edu)
* \date   7/28/23
"""

"""
Description:

This script is used to calculate the cell configuration for the scene builder.
It takes all measurements which were measured by each robot (with respect to the planning group frame, base_link,
and transforms them to the world frame. Then, it calculates the cell configuration with respect to the world frame.

"""


import numpy as np
from scipy.spatial.transform import Rotation as R

if __name__ == "__main__":
    # first lets define the homogenious transformation matrix from the base_link of arm 1 to the world frame
    # by shifting it 0.9667748 meters in the z axis
    R_1_w = R.from_euler('xyz', [0, 0, 0], degrees=True).as_matrix()
    t_1_w = np.array([0, 0, 0.9667748])
    T_1_w = np.eye(4)
    T_1_w[:3, :3] = R_1_w
    T_1_w[:3, 3] = t_1_w

    # now lets define the homogenious transformation matrix from the base_link of arm 2 to the world frame
    # we will do it using two points measured by arm 2 and arm 1
    joint_pt_1_arm1 = np.array([[0.34282, 0.59834, -0.004173]])
    joint_pt_2_arm1 = np.array([[0.341429, 1.20999, -0.0348543]])
    joint_pt_1_arm2 = np.array([[0.168759, -0.538351, -0.004173]]) #0.0306813]])
    joint_pt_2_arm2 = np.array([[-0.446216, -0.533426, -0.0348543]])# -0.004173]])

    vec_2 = np.array([[-(joint_pt_1_arm2 - joint_pt_2_arm2)[0, 1], -(joint_pt_1_arm2 - joint_pt_2_arm2)[0, 0], (joint_pt_1_arm2 - joint_pt_2_arm2)[0, 2]]])
    vec_1 = joint_pt_1_arm1 - joint_pt_2_arm1
    # get the angle between the two vectors
    angle = np.arccos(np.dot(vec_1, vec_2.T) / (np.linalg.norm(vec_1) * np.linalg.norm(vec_2)))
    yaw = angle[0][0] - np.pi/2
    R_2_1 = R.from_euler('zyx', [-yaw, 0, 0], degrees=False).as_matrix()
    # now lets calculate the translation vector
    t_2_1 = joint_pt_1_arm1 - (R_2_1.T@joint_pt_1_arm2.T).T
    t_2_1[0, 2] = 0.942975 - 0.9667748
    T_2_1 = np.eye(4)
    T_2_1[:3, :3] = R_2_1
    T_2_1[:3, 3] = t_2_1[0]

    # now lets define the homogenious transformation matrix from the base_link of arm 3 to the world frame
    T_2_w = T_1_w@T_2_1


    # now lets define the homogenious transformation matrix from the base_link of arm 3 to the world frame
    # we will do it using two points measured by arm 3 and arm 1
    joint_pt_1_arm1 = np.array([[0.342911, -0.620022, -0.00472]])
    joint_pt_2_arm1 = np.array([[0.349312, -0.916371, -0.025155]])
    joint_pt_1_arm3 = np.array([[0.135752, 0.615211, 0.0218598]]) #0.0306813]])
    joint_pt_2_arm3 = np.array([[-0.158122, 0.612251, -0.00411]])# -0.004173]])

    vec_1 = joint_pt_1_arm1 - joint_pt_2_arm1
    vec_2 = np.array([[(joint_pt_1_arm3 - joint_pt_2_arm3)[0, 1], (joint_pt_1_arm3 - joint_pt_2_arm3)[0, 0],
                       vec_1[0, 2]]]) # (joint_pt_1_arm3 - joint_pt_2_arm3)[0, 2]]])

    # get the angle between the two vectors
    angle = np.arccos(np.dot(vec_1, vec_2.T) / (np.linalg.norm(vec_1) * np.linalg.norm(vec_2)))
    yaw = angle[0][0] + np.pi/2
    R_3_1 = R.from_euler('zyx', [-yaw, 0, 0], degrees=False).as_matrix()
    # now lets calculate the translation vector
    t_3_1 = joint_pt_1_arm1 - (R_3_1.T@joint_pt_1_arm3.T).T
    t_3_1[0, 2] = 0.9445498 - 0.9667748
    T_3_1 = np.eye(4)
    T_3_1[:3, :3] = R_3_1
    T_3_1[:3, 3] = t_3_1[0]

    # now lets define the homogenious transformation matrix from the base_link of arm 3 to the world frame
    T_3_w = T_1_w@T_3_1

    i=0

